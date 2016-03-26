class Solution {
public:

    /*
    * O(n^2)
    * dp[i] represents the length of LIS ending with nums[i]
    * dp[i] = max(dp[j]+1) while 0 <= j < i and nums[i] > nums[j]
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (res < dp[i]) res = dp[i];
        } 
        return res;
    }
};

