/*Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

class Solution {
public:
    
    // dp(i,j) = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : 0;
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> pre(n+1, 0), cur(n+1, 0);
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]) cur[j] = pre[j-1] + 1;
                else cur[j] = 0;
                res = max(res, cur[j]);
            }
            pre = cur;
        }
        return res;
    }
};
