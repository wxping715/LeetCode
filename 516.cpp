/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    
    // dp(i, j) = dp(i+1, j-1) + 2, s[i] == s[j]
    //            max(dp(i+1, j), dp(i, j-1))
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for (int l = 2; l <= n; l++)
            for (int i = 0; i+l <= n; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = (i+1 < j ? dp[i+1][j-1] : 0) + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
    
        if (n == 0) return 0;
        return dp[0][n-1];
    }
};
