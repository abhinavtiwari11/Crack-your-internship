class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
 vector<vector<int>> adj(n+1,vector<int>());
        int m=trust.size();
        for(int i=0;i<m;i++){
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        vector<vector<int>> adj1(n+1,vector<int>());
        for(int i=0;i<m;i++){
            adj1[trust[i][1]].push_back(trust[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0 && adj1[i].size()==n-1)return i;
            else continue;
        }
        return -1;
    }
};