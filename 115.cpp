/*Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:
    
    // dp[i][j] means the solutions try to convert s(0,i) to t(0,j)
    // 1. if s[i] == t[j], dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    // 2. otherwise, dp[i][j] = dp[i-1][j]
    // dp[i][0] = 1
    int numDistinct(string s, string t) {
        if (t.length() > s.length()) return 0;
        
        vector<int> pre(t.size()+1, 0), cur(t.size()+1, 0);
        for (int i = 1; i <= s.length(); i++) {
            pre[0] = 1;
            for (int j = 1; j <= t.length(); j++) {
                if (s[i-1] == t[j-1]) cur[j] = pre[j-1] + pre[j];
                else cur[j] = pre[j];
            }
            pre = cur;
        }
        return pre[t.length()];
    }
};
