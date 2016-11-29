class Solution {
public:
    /*
    * O(n^2)
    */
    // int lengthOfLIS(vector<int>& nums) {
    //     if (nums.empty()) return 0;
        
    //     vector<int> dp(nums.size(), 1);
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++)
    //             if (nums[j] < nums[i])
    //                 dp[i] = max(dp[i], dp[j]+1);
    //     }
        
    //     int maxl = 1;
    //     for (int i = 0; i < nums.size(); i++)
    //         if (maxl < dp[i])
    //             maxl = dp[i];
    //     return maxl;
    // }
    
    /**
     * O(nlogn)
    **/
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int len = 0;
        for (int n : nums) {
            int pos = lower_bound(dp.begin(), dp.begin()+len, n) - dp.begin();
            dp[pos] = n;
            len = max(len, pos+1);
        }
        
        return len;
    }
};
