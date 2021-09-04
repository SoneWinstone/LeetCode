/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
//// 最简单解法：递归
//     vector<int> rst{};
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (root != nullptr) {
//             inorderTraversal(root->left);
//             rst.push_back(root->val);
//             inorderTraversal(root->right);
//         }
//         return rst;
//     }

// // 模拟栈解法
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> rst{};
//         stack<TreeNode*> stack{};
//         while  (root != nullptr || !stack.empty()) {
//             if (root != nullptr) {
//                 stack.push(root);
//                 root = root->left;
//             } else {
//                 root = stack.top();
//                 stack.pop();
//                 rst.push_back(root->val);
//                 root = root->right;
//             }
//         }
   
//         return rst;
//     }

// 二叉树转链表
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rst{};
        // 前驱节点 当前根节点左孩子的最右节点，让前驱节点指向当前根节点
        TreeNode* predecessor = nullptr;
        TreeNode* temp = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                // 前驱节点指向当前根节点
                predecessor->right = root;
                temp = root;
                // 根节点变成左孩子
                root = root->left;
                // 之前的根节点左孩子变为nullptr
                temp->left = nullptr;
            } else {
                // 已经将二叉树转成链表，且当前节点是链表头 遍历输出
                rst.push_back(root->val);
                root = root->right;
            }
        }
   
        return rst;
    }
};
