//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 
// 👍 1274 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
            cout << "left: " << left << ", right: " << right << endl;

            while (valid == need.size()) {
                // 如果得到的新区间比之前的区间短，就更新区间信息
                if ((right - left) < len) {
                    start = left;
                    len = right - left;
                    cout << "-------------------------" << endl;
                    cout << "left: " << left << ", right: " << right << endl;
                    cout << s.substr(start, len) << endl;
                    cout << endl;
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s = "aaaaaaaaaaaabbbbbcdd";
    string t = "abcdd";
    Solution solution;
    string rst = solution.minWindow(s, t);
    cout << "rst: " << rst << endl;
    return 0;
}
