/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        int k = 1;
        for (int i = 1; i <= n; i++) {
            if (k*k == i) {
                dp[i] = 1;
                k++;
            }
            else {
                // k*k > i
                for (int j = 1; j < k; j++)
                    dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
