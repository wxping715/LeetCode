class Solution {
public:
    /*
    * O(n^2) algorithm
    * dp[i] means the maximul product that break at leaat once, not two integers.
    * dp[i] = max(dp[i-j]*j) where 1 <= j <= i.
    * res = max(dp[i-j]*j) where 1 <= j < i.
    */
    int integerBreak(int n) {
        if (n == 0 || n == 1) return 0;
        
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                dp[i] = max(dp[i], dp[i-j]*j);
        }
        
        int res = 0;
        for (int i = 1; i < n;i++)
            res = max(res, dp[n-i]*i);
        return res;
    }
};


