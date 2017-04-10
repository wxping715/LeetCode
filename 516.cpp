class Solution {
public:

    /*
    * dp(i,j) means the longest value from i and j
    * dp(i,j) = s[i] == s[j] : dp(i+1, j-1)+2 : max(dp(i, j-1), dp(i+1, j))
    */
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        int dp[s.length()][s.length()] = {0};
        for (int i = 0; i < s.length(); i++) dp[i][i] = 1;
        for (int i = 0; i+1 < s.length(); i++) dp[i][i+1] = s[i] == s[i+1] ? 2 : 1;
        
        for (int l = 3; l <= s.length(); l++)
            for (int i = 0; i+l <= s.length(); i++) {
                int j = i+l-1;
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1]+2 : max(dp[i][j-1], dp[i+1][j]);
            }
        
        return dp[0][s.length()-1];
    }
    
    /*
    * TODO: optimize spaces
    */
};
