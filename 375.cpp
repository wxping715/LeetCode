class Solution {
public:

    /*
    * dp[i][j] means minimum maximum loss
    * dp[i][j] = min(k+max(dp[i][k-1], dp[k+1][j])), i <= k <= j
    */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int l = 1; l <= n; l++) {
            for (int i = 1; i+l <= n+1; i++) {
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                if (i == j) dp[i][j] = 0;
                else {
                    for (int k = i; k <= j; k++) {
                        int t = INT_MIN;
                        if (k-1 >= i) t = max(t, dp[i][k-1]);
                        if (k+1 <= j) t = max(t, dp[k+1][j]);
                        dp[i][j] = min(dp[i][j], k+t);
                    }
                }
            }
        }
        return dp[1][n];
    }
    
    /*
    * the second type of loop
    */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = n-1; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = INT_MAX;
                if (i == j) dp[i][j] = 0;
                else {
                    for (int k = i; k <= j; k++) {
                        int t = INT_MIN;
                        if (k-1 >= i) t = max(t, dp[i][k-1]);
                        if (k+1 <= j) t = max(t, dp[k+1][j]);
                        dp[i][j] = min(dp[i][j], k+t);
                    }
                }
            }
        }
        return dp[1][n];
    }
};
