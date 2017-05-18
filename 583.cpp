class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m+1][n+1] = {0};
        
        dp[0][0] = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) dp[i][j] = i == 0 ? j : i;
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    if (word1[i-1] == word2[j-1]) 
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
