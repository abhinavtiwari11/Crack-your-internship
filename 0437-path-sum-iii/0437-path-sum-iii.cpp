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
public:

    long long sum = 0;
    int count = 0;
    void dfs(TreeNode* root, int target){
        if(root == NULL) return;

        sum += root->val;
        if(sum == target) count++;
        dfs(root->left, target);
        dfs(root->right, target);
        sum -= root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};