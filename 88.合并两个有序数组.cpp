/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (44.89%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    60.3K
 * Total Submissions: 134.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1
 * 成为一个有序数组。
 *
 * 说明:
 *
 *
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2
 * 中的元素。
 *
 *
 * 示例:
 *
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * 输出: [1,2,2,3,5,6]
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void move(vector<int> &vec, int index, int last) {
    while (--last > index) {
      vec[last] = vec[last - 1];
    }
  }

public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i1 = 0, i2 = 0, index = 0, cnt = 0, total = m;
    for (; i1 < m && i2 < n;) {
      if (nums1[index] <= nums2[i2]) {
        ++i1;
      } else {
        move(nums1, index, ++total);
        nums1[index] = nums2[i2++];
      }
      ++index;
    }

    if (i1 == m) {
      while (i2 < n) {
        move(nums1, index, ++total);
        nums1[index++] = nums2[i2++];
      }
    }
  }
};
