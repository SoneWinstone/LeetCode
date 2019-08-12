/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (49.79%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    34K
 * Total Submissions: 68.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 *
 * 输入为非空字符串且只包含数字 1 和 0。
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 */
class Solution {
public:
  string addBinary(string a, string b) {
    string ret;
    auto cra = a.crbegin();
    auto crb = b.crbegin();
    bool carry = false;
    for (; cra < a.crend() && crb < b.crend(); ++cra, ++crb) {
      ret.insert(ret.begin(),
                 ((((*cra) - '0' + (*crb) - '0')) + carry) % 2 + '0');
      carry = ((((*cra) - '0' + (*crb) - '0')) + carry >= 2);
    }
    while (cra < a.crend()) {
      ret.insert(ret.begin(), (((*cra) - '0') + carry) % 2 + '0');
      carry = (((*cra) - '0') + carry == 2);
      ++cra;
    }
    while (crb < b.crend()) {
      ret.insert(ret.begin(), (((*crb) - '0') + carry) % 2 + '0');
      carry = (((*crb) - '0') + carry == 2);
      ++crb;
    }
    if (carry) {
      ret.insert(ret.begin(), '1');
    }
    return ret;
  }
};
