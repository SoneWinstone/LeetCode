/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window{};
        unordered_map<char, int> need{};
        for (char c : s1) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            auto it = need.find(c);
            ++right;
            if (it != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

             while (valid == need.size()) {
                // 子串比所需的串长
                if (right - left > s1.size()) {
                    char lc = s2[left];
                    auto lit = need.find(lc);
                    if (lit != need.end()) {
                        if (window[lc] == need[lc]) {
                            valid--;
                        }
                        window[lc]--;
                    }
                    ++left;
                } else if (right - left == s1.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

