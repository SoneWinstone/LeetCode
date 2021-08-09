/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window{};

        int len = 0;
        int left = 0, right = 0;
        while (right < s.length()) {
            char c = s[right];
            right++;
            window[c]++;
            if (window[c] == 1) {
                len = max(len, static_cast<int>(window.size()));
            } else {
                char lc = s[left];
                while (lc != c) {
                    window.erase(lc);
                    left++;
                    lc = s[left];
                }
                window[lc]--;
                left++;
            }
        }

        return len;
    }
};
// @lc code=end

