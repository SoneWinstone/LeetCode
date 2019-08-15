/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (61.67%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 35.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其自底向上的层次遍历为：
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
  vector<vector<int>> ret;
  int getLevels(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(getLevels(root->left), getLevels(root->right));
  }
  void levelOrderBottom(TreeNode *root, int level) {
    if (root == nullptr) {
      return;
    }
    levelOrderBottom(root->left, level + 1);
    levelOrderBottom(root->right, level + 1);
    ret[ret.size() - level].push_back(root->val);
    //        vector<int>& vi = ret[ret.size() - level];
    //        vi.push_back(root->val);
  }

public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    int levels = getLevels(root);
    for (int i = 0; i < levels; ++i) {
      vector<int> vi;
      ret.push_back(vi);
    }
    levelOrderBottom(root, 1);
    return ret;
  }
};
