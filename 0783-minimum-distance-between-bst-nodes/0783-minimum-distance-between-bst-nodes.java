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
   Integer cur =  null;
    int ans = Integer.MAX_VALUE;

    public int minDiffInBST(TreeNode root) {
        minDiff(root);
        return ans;
    }

    private void minDiff(TreeNode node) {
        if (node == null) return;
        
        minDiff(node.left);

        if (cur != null) ans = Math.min(ans, node.val - cur);

        cur = node.val;

        minDiff(node.right);
        
    }

}