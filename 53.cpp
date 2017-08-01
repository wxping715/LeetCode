/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

dp[i] = dp[i-1]+nums[i]   dp[i-1]>0
        nums[i]     otherwise
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++)
            dp[i] = dp[i-1] >= 0 ? dp[i-1] + nums[i] : nums[i];
        
        int res = INT_MIN;
        for (int i = 1; i <= nums.size(); i++)
            res = max(res, dp[i]);
        return res;
    }
};
