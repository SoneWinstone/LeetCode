/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        return trave(root, false);
    }

    public int trave(TreeNode node, boolean isLeft) {
        if (node == null) {
            return 0;
        }
        int left = trave(node.left, true);
        int right = trave(node.right, false);
        if (isLeft && node.left == null && node.right == null) {
            return left + right + node.val;            
        } 
        return left + right;
    }
}
