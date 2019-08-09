/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (63.76%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 7K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组
 * A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现
 * 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 *
 * 你可以按任意顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 *
 *
 * 示例 2：
 *
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 *
 *
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
  map<char, int> cMap;

public:
  vector<string> commonChars(vector<string> &A) {
    vector<string> ret;

    int temp = INT32_MAX;
    auto shortest = [&temp](vector<string> &ss) -> int {
      for (string s : ss) {
        if (s.length() < temp) {
          temp = s.length();
        }
      }
      return temp;
    }(A);

    for (string s : A) {
      if (s.length() == shortest) {
        for (char c : s) {
          auto iter = cMap.find(c);
          if (iter != cMap.end()) {
            iter->second++;
          } else {
            cMap.insert(pair<char, int>(c, 1));
          }
        }
        break;
      }
    }

    for (string s : A) {
      for (auto &cm : cMap) {
        size_t cnt = 0;
        for (char c : s) {
          if (cm.first == c) {
            ++cnt;
            if (cnt >= cm.second) {
              break;
            }
          }
        }
        if (cnt < cm.second) {
          cm.second = (int)cnt;
        }
      }
    }

    for (auto cm : cMap) {
      for (int i = 0; i < cm.second; ++i) {
        ret.emplace_back(string() + cm.first);
      }
    }
    return ret;
  }
};
