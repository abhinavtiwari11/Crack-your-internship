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
    
        
     std::unordered_map<int, int> record;
    void visit(TreeNode* root) {
        if(root->left) {
            visit(root->left);
        }
        
        record[root->val]++;

        if(root->right) {
            visit(root->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        auto comp = [](std::pair<int, int> lhs, std::pair<int, int> rhs)->bool {
            return lhs.second < rhs.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, decltype(comp)> q(comp);
        visit(root);

        for(auto p : record) {
            q.push(pair(p.first, p.second));
        }

        int maxV = q.top().second;
        std::vector<int> ret{q.top().first};
        q.pop();

        while(!q.empty() && q.top().second == maxV) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};