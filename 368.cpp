class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int midx = 0, mres = 0;
        vector<int> pre(nums.size(), -1), dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                    
                    if (mres < dp[i]) {
                        mres = dp[i];
                        midx = i;
                    }
                }
                // cout << i << " " << dp[i] << endl;
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < mres; i++) {
            ret.push_back(nums[midx]);
            midx = pre[midx];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
