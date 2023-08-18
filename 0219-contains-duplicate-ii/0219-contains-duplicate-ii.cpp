class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
      int n=nums.size();
      
        
        int i=0;
        int j;
        set<int> val;

        while(i<=k) {
            if(i==n)
                break;
                
            if(val.count(nums[i]))
                return true;
            val.insert(nums[i]);
            i++;
        }

        // sliding window
        while(i<n) {
            val.erase(nums[i-k-1]);
            if(val.count(nums[i]))
                return true;

            val.insert(nums[i]);
            i++;
        }
        
        return false;
    }
};