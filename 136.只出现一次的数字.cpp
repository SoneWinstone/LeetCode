/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (62.59%)
 * Likes:    797
 * Dislikes: 0
 * Total Accepted:    90.3K
 * Total Submissions: 143.8K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 说明：
 *
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 示例 1:
 *
 * 输入: [2,2,1]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * 输入: [4,1,2,1,2]
 * 输出: 4
 *
 */
class Solution {
private:
  map<int, int> mapI;

  int way1(vector<int> &nums) {
    for (const int i : nums) {
      auto location = mapI.find(i);
      if (location == mapI.end()) {
        mapI.insert(pair<int, int>(i, 1));
      } else {
        ++(*location).second;
      }
    }
    for (pair<int, int> pair : mapI) {
      if (pair.second == 1) {
        return pair.first;
      }
    }
    return -1;
  }

  int way2(vector<int> &nums) {
    int ret = 0;
    for (const int i : nums) {
      ret = ret ^ i;
    }
    return ret;
  }

public:
  int singleNumber(vector<int> &nums) { return way2(nums); }
};
