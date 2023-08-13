class Solution {
    public boolean validPartition(int[] nums) {
        
    
    Boolean[] dp = new Boolean[nums.length];
    
    return find(0, nums, dp);
}

private boolean find( int index, int[] nums, Boolean[] dp ){
    
    if( index == nums.length ) return true;
    
    if( index > nums.length ) return false;
    
    if( dp[index] != null ) return dp[index];
    
    if( index + 1 < nums.length ) {
        if( nums[index] == nums[index+1] && find(index+2, nums, dp) ) {
            dp[index] = true;
            return true;
        }
    }
    
    if( index+2 < nums.length ){
        
        if( nums[index] == nums[index+1] && nums[index] == nums[index+2] && find(index+3, nums, dp) ) return dp[index] = true;
            
        
        if( nums[index+1] == (nums[index]+1) && nums[index+2] == (nums[index]+2) && find(index+3, nums, dp) ) return dp[index] = true;
    }
    
    return dp[index] = false;
}
};