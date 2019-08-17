/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.54%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 116.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 * 示例 1:
 *
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "race a car"
 * 输出: false
 *
 *
 */
class Solution {
public:
  bool isPalindrome(string s) {
    int len = s.length();
    char *arrC = new char[len];

    int index = 0;
    for (char c : s) {
      if (isalpha(c)) {
        if (isupper(c)) {
          arrC[index++] = tolower(c);
        } else {
          arrC[index++] = c;
        }
      } else if (isdigit(c)) {
        arrC[index++] = c;
      }
    }
    for (int i = 0; i < index / 2; ++i) {
      if (arrC[i] != arrC[index - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
