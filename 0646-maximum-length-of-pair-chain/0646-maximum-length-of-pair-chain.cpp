class Solution {
public:
    bool static comp(vector<int> &v1,vector<int> &v2)
   {
       return v1[1]<v2[1];
   }
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        // for(int i=0;i<v.size();i++) cout<<v[i][0]<<" "<<v[i][1]<<"    ";
        vector<int> res;
        if(v.size()==1) return 1;
        int n=v.size();
        vector<int> dp(n+1,0);
        dp[1]=1;
        res.push_back(-1001);
        res.push_back(v[0][1]);
        for(int i=2;i<=n;i++)
        {
            int ind=lower_bound(res.begin(),res.end(),v[i-1][0])-res.begin();
            // cout<<ind<<" ";
            dp[i]=max(dp[i-1],1+dp[ind-1]);
            res.push_back(v[i-1][1]);
        }
        return dp[n];
    }
};