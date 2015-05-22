int maxSubArray(int* nums, int numsSize) {

    int dp[numsSize + 1];
    
    dp[0] = 0;
    for(int i = 1;i <= numsSize;i++)
        dp[i] = dp[i-1] >= 0 ? dp[i-1] + nums[i-1] : nums[i-1];
    
    int max = -99999999;    
    for(int i = 1;i <= numsSize;i++)
        max = max > dp[i] ? max : dp[i];
        
    return max;
}
