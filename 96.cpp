class Solution {
public:
    /*
    * dp[i] = sum(dp[k]*dp[i-1-k]), where 0 <= k <= i-1
    * dp[0] = 1, dp[1] = 1
    */
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1; dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i-1; j++) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
