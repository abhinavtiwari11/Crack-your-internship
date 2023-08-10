class Solution {
public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans;
        vector<int>dp(1001,0);
        for(auto &it : nums2)
        {
            dp[it] = 1;
        }
        for(auto &it : nums1)
        {
            if(dp[it] == 1)
            {
                ans.push_back(it);
                dp[it] = 0;
            }
        }
        return ans;
        
    }
};