class Solution {
public:
    /*
    * dp(i,j) means the minimum cut from i to j
    * dp(i,j) = min(dp(i,k)+dp(k+1,j)+1)  
    * O(N^3)
    */
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, n));
        vector<vector<bool>> palind(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            palind[i][i] = true;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i+l <= n; i++) {
                int j = l+i-1;
                bool isPalind = (s[i] == s[j]) && (l == 2 || palind[i+1][j-1]);
                if (isPalind) dp[i][j] = 0;
                else
                    for (int k = i; k+1 <= j; k++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]+1);
                palind[i][j] = isPalind;
            }
        }
        return dp[0][n-1];
    }
    
    /*
    * dp[i] means the minimum cut from i to n-1
    * O(n^2)
    */
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        bool palind[n][n] = {false};
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i-j<=1 || palind[j+1][i-1])) {
                    palind[j][i] = true;
                    dp[i] = (j == 0 ? 0 : min(dp[i], dp[j-1]+1)); 
                }
            }
        }
        return dp[n-1];
    }
};
