/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        
        vector<int> dp(n+1, 0);
        int perm = 9;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            perm = perm * (10 - i + 1);
            dp[i] = dp[i-1] + perm;
        }
        return dp[n];
    }
};
