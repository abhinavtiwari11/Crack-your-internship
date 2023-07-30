
class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int n = nums.length;
        if(n == 1) return nums[0];

        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s<e) 
        {
            if(nums[mid] != nums[mid+1]) {
                int len = e-mid;
                if(len%2 == 0) {
                    e = mid;
                }
                else {
                    s = mid+1;
                }
            }
            else {
                int len = e - (mid-1);
                if(len % 2 == 0) {
                    e = mid-1;
                }
                else {
                    s = mid;
                }
            }

            mid = s + (e-s)/2;
        }
        return nums[s];
    }
}
