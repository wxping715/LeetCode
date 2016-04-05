class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        
        int dp[n+1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        
        for (int i = 1;i <= n;i++) {
            if ((int)sqrt(i)*(int)sqrt(i) == i) dp[i] = 1;
            else {
                for (int j = 1; j*j < i; j++) 
                    if (dp[i] > dp[j*j] + dp[i-j*j])
                        dp[i] = dp[j*j] + dp[i-j*j];
            }
        }
        return dp[n];
    }
};
