/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
    
    // determine whether palindromic
    // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        
        int r = n;
        for (int l = 2; l <= n; l++)
            for (int i = 0; i+l <= n; i++) {
                int j = i+l-1;
                if (s[i] == s[j]) {
                    if (l == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }
                
                if (dp[i][j]) r++;
            }
        return r;
    }
};
