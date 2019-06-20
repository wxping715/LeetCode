/*
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

*/

class Solution {
    // dp(i, j) = min(dp[i-1, j-1], dp(i-1, j), dp(i-1, j+1)) + A[i]
    public int minFallingPathSum(int[][] A) {
        if (A == null || A[0] == null) return 0;
        int n = A.length, m = A[0].length;
        int[] prev = new int[m], curr = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                curr[j] = prev[j];
                if (j-1 >= 0) curr[j] = Math.min(curr[j], prev[j-1]);
                if (j+1 < m) curr[j] = Math.min(curr[j], prev[j+1]);
                curr[j] += A[i][j];
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        
        int ans = 0;
        for (int j = 0; j < m; j++) {
            if (j == 0) ans = prev[j];
            else ans = Math.min(ans, prev[j]);
        }
        return ans;
    }
}
