//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。 
//
// 换句话说，s1 的排列之一是 s2 的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "ab" s2 = "eidbaooo"
//输出：true
//解释：s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入：s1= "ab" s2 = "eidboaoo"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 104 
// s1 和 s2 仅包含小写字母 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 
// 👍 395 👎 0

#include <iostream>
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    // 18200
    // 04808
    // 00910
    // 61852
    string s1 = "abcdxabcde";
    string s2 = "abcdeabcdx";
    Solution solution;
    cout << solution.checkInclusion(s1, s2) << endl;
    return 0;
}
