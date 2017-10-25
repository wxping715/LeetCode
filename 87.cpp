/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.


*/

class Solution {
public:
    
    bool isScramble(string s1, string s2) {
        //dp(l,i,j) means if i,i+l-1 can scramble to j, j+l-1
        if (s1.length() != s2.length())
            return false;
        
        int n = s1.length();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n, vector<int>(n, false)));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[1][i][j] = s1[i] == s2[j];
        
        for (int l = 2; l <= n; l++)
            for (int i = 0; i+l <= n; i++)
                for (int j = 0; j+l <= n; j++)
                    for (int k = 1; k < l; k++) {
                        dp[l][i][j] = dp[l][i][j] || (dp[k][i][j] && dp[l-k][i+k][j+k]) ||
                                      (dp[k][i][j+l-k] && dp[l-k][i+k][j]);
                    }
        return dp[n][0][0];
    }
};
