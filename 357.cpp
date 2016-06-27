class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int dp[n+1], perm = 9;
        dp[1] = 10; 
        for (int i = 2;i <= n;i++) {
            perm *= 10 - i + 1;
            dp[i] = dp[i-1] + perm;
        }
        return dp[n];
    }
};
