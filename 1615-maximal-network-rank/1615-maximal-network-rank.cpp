class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
   
         vector<int> indegree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        for (const auto& road : roads) {
            indegree[road[0]]++;
            indegree[road[1]]++;
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = indegree[i] + indegree[j];
                if (connected[i][j]==true) {
                    rank--;
                }
                maxi = max(maxi, rank);
            }
        }

        return maxi;
    }
};