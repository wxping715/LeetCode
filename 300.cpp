/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

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
