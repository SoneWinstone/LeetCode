/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (34.05%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 33K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 *
 * 例如，
 *
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 * ⁠   ...
 *
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: "A"
 *
 *
 * 示例 2:
 *
 * 输入: 28
 * 输出: "AB"
 *
 *
 * 示例 3:
 *
 * 输入: 701
 * 输出: "ZY"
 *
 *
 */
class Solution {
  void convertToTitle(int n, string &str) {
    if (n % 26 == 0) {
      str.insert(str.begin(), 'Z');
      n = n / 26 - 1;
    } else {
      str.insert(str.begin(), n % 26 + 'A' - 1);
      n = n / 26;
    }
    while (n > 0) {
      if (n % 26 == 0) {
        str.insert(str.begin(), 'Z');
        n = n / 26 - 1;
      } else {
        str.insert(str.begin(), n % 26 + 'A' - 1);
        n = n / 26;
      }
    }
  }

public:
  string convertToTitle(int n) {
    string ret;
    convertToTitle(n, ret);
    return ret;
  }
};
