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
    
 void path(TreeNode *root,vector<string> &ans,string res)
    {
        if(root==0)
        return;

        if(root->left==0 && root->right==0)
        {
            res+=to_string(root->val);
            ans.push_back(res);
            return;
        }

        path(root->left,ans,res+to_string(root->val)+"->");
        path(root->right,ans,res+to_string(root->val)+"->");

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> v;
        path(root,v,"");
        return v;
    }
};