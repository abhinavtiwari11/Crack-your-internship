class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, int> freqMap;
        unordered_map<int, int> startIndex;
        int maxDegree = 0;
        int minLength = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (startIndex.find(nums[i]) == startIndex.end()) {
                startIndex[nums[i]] = i;
            }
            freqMap[nums[i]]++;

            if (freqMap[nums[i]] > maxDegree) {
                maxDegree = freqMap[nums[i]];
                minLength = i - startIndex[nums[i]] + 1;
            } else if (freqMap[nums[i]] == maxDegree) {
                minLength = min(minLength, i - startIndex[nums[i]] + 1);
            }
        }

        return minLength;
    }
};
