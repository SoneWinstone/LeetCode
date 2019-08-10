/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (46.62%)
 * Likes:    1102
 * Dislikes: 0
 * Total Accepted:    78.4K
 * Total Submissions: 167.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组
 * nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 示例:
 *
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 *
 *
 * 进阶:
 *
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    int ret = nums[0];
    int temp = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > ret) {
        if (nums[i] > (temp + nums[i])) {
          ret = nums[i];
          temp = nums[i];
        } else {
          ret = nums[i] + temp;
          temp = nums[i] + temp;
        }
      } else if ((nums[i] + temp) >= ret) {
        ret = nums[i] + temp;
        temp = nums[i] + temp;
      } else {
        if (nums[i] > (temp + nums[i])) {
          temp = nums[i];
        } else {
          temp += nums[i];
        }
      }
    }
    return ret;
  }
};
