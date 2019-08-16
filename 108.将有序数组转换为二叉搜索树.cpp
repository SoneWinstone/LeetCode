/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (65.58%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 40.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 *
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过
 * 1。
 *
 * 示例:
 *
 * 给定有序数组: [-10,-3,0,5,9],
 *
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    TreeNode *ret;
    int medium = (start + end) / 2;
    ret = new TreeNode(nums[medium]);
    ret->left = sortedArrayToBST(nums, start, medium - 1);
    ret->right = sortedArrayToBST(nums, medium + 1, end);
    return ret;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }

    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};
