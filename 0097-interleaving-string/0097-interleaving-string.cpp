class Solution {
public:
    
bool solve(string s1,string s2,string s3,int a,int b,int c,vector<vector<int>> &dp)
{
        
    
    if(a<0 && b<0 && c<0)
    return true;

    if(a>=0 && b>=0 && dp[a][b]!=-1)
    return dp[a][b];

    if(a>=0 && s1[a]==s3[c] && b>=0 && s2[b]==s3[c])
    return dp[a][b]=(solve(s1,s2,s3,a-1,b,c-1,dp)||solve(s1,s2,s3,a,b-1,c-1,dp));
    else if(a>=0 && s1[a]==s3[c])
    return solve(s1,s2,s3,a-1,b,c-1,dp);
    else if(b>=0 && s2[b]==s3[c])
    return solve(s1,s2,s3,a,b-1,c-1,dp);
    else
    return false;
}
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s3.size()!=s1.size()+s2.size())
        return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1,dp);
        
    }
};
