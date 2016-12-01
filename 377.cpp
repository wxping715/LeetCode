class Solution {
public:
    
    /**
     * dp[i] = dp[i-nums[j]] 0 <= j <= nums.size()
     **/
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int num : nums)
                if (num <= i)
                    dp[i] += dp[i-num];
        return dp[target];
    }
};
