//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 异位词 指字母相同，但排列不同的字符串。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 104 
// s 和 p 仅包含小写字母 
// 
// Related Topics 哈希表 字符串 滑动窗口 
// 👍 579 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s1 = "abab";
    string s2 = "ab";
    Solution solution;
    auto vec = solution.findAnagrams(s1, s2);

    cout << "[";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << ",";
    }
    cout << "\b]" << endl;

    return 0;
}