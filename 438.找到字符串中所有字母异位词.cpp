/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ret{};

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
            if (it != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            ++right;

            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    ret.push_back(left);
                }

                char lc = s2[left];
                auto lit = need.find(lc);
                if (lit != need.end()) {
                    if (window[lc] == need[lc]) {
                        valid--;
                    }
                    window[lc]--;
                }
                ++left;
            }
        }
        return ret;
    }
};
// @lc code=end

