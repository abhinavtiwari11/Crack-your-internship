class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
      vector<int>Res;
        priority_queue<pair<int,int>>A;
        for(int i=0;i<nums.size();i++){
            if(i<k-1){
                A.push({nums[i],i});
            }
            else{
                A.push({nums[i],i});
                while(A.top().second<i+1-k){
                    A.pop();
                }
                    Res.push_back(A.top().first);
            }
        }
        return Res;
    }
};