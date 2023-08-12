class Solution{
    public:
int uniquePathsWithObstacles(vector<vector<int>>& obsGrd) {
        int rows = obsGrd.size(), cols = obsGrd[0].size();
        vector<vector<int>> pathCnt(rows, vector<int>(cols, 0));
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(r== 0 && c == 0){
                    pathCnt[r][c] = (obsGrd[r][c] == 1 ? 0 : 1);
                }else{
                    int leftPathCnt = (c - 1 > -1 && obsGrd[r][c-1] != 1) ? pathCnt[r][c-1] : 0;
                    int upPathCnt = (r -1 > -1 && obsGrd[r-1][c] != 1) ? pathCnt[r-1][c] : 0;
                   if(obsGrd[r][c] != 1) 
                    pathCnt[r][c] += leftPathCnt + upPathCnt;
                }
            }
        }
        return pathCnt[rows-1][cols-1];
    }
};