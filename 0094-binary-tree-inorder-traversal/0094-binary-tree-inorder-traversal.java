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
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        inOrder(root,result);
        return result;
    }
    public void inOrder(TreeNode root, ArrayList<Integer> result){
        //terminating condition
        if(root==null){
            return;
        }
        //recursively call inOrder on the left subtree
        inOrder(root.left,result);
        // add the current node's value to the result list
        result.add(root.val);
        // recursively call inOrder on the right subtree
        inOrder(root.right,result);
    }
}