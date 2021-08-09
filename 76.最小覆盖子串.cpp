/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

            unordered_map<char, int> need{};
        unordered_map<char, int> window{};
        for (char c : t) {
            // need[c]不存在时会默认设为0，再++
            need[c]++;
        }

        int left = 0, right = 0;
        // 记录有效字符
        int valid = 0;
        int start = 0, len = INT32_MAX;
        while (right < s.size()) {
            auto it = need.find(s[right]);
            if (it != need.end()) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    ++valid;
                }
            }

            ++right;

            while (valid == need.size()) {
                // 如果得到的新区间比之前的区间短，就更新区间信息
                if ((right - left) < len) {
                    start = left;
                    len = right - left;
                }
                auto leftIt = need.find(s[left]);
                if (leftIt != need.end()) {
                    if (window[s[left]] == need[s[left]]) {
                        --valid;
                    }
                    window[s[left]]--;
                }
                ++left;
            }
        }

        if (len == INT32_MAX) {
            return "";
        }
        return s.substr(start, len);
    }
};
// @lc code=end

