/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:
    /*
    * dp[i] = sum(dp[k]*dp[i-1-k]), where 0 <= k <= i-1
    * dp[0] = 1, dp[1] = 1
    */
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1; dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i-1; j++) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
