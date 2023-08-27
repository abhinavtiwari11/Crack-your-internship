class Solution {
public:
   unordered_map<int,int> mp;
int dp[2001][2001];
bool solve(int i,int prev,vector<int>& stones){
    if(i==stones.size()-1){
        return true;
    }
    if(dp[i][prev]!=-1){
        return dp[i][prev];
    }
    bool tkn=false,tk=false,tkp=false;
    if(prev-1>0 && mp.find(stones[i]+prev-1)!=mp.end()){
        tkn=solve(mp[stones[i]+prev-1],prev-1,stones);
    }
    if(prev>0 && mp.find(stones[i]+prev)!=mp.end()){
        tk=solve(mp[stones[i]+prev],prev,stones);
    }
    if(prev+1>0 && mp.find(stones[i]+prev+1)!=mp.end()){
        tkp=solve(mp[stones[i]+prev+1],prev+1,stones);
    }
    return dp[i][prev]=tkn || tk || tkp;
}
    bool canCross(vector<int>& stones) {
        mp.clear();
        memset(dp,-1,sizeof(dp));
        int n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        bool ans=solve(0,0,stones);
        return ans;

    }
};
