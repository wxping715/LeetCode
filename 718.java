/*
718. Maximum Length of Repeated Subarray
Medium

650

29

Favorite

Share
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
*/

class Solution {
    // dp(i, j) the max subarray end with i and j
    // dp(i, j) = dp(i-1, j-1) + 1 in case of A[i] == B[j] else 0
    public int findLength(int[] A, int[] B) {
        int m = A.length, n = B.length;
        int ans = 0;
        int[] prev = new int[n];
        int[] curr = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i] != B[j]) curr[j] = 0;
                else if (A[i] == B[j]) curr[j] = j > 0 ? prev[j-1]+1 : 1;
                ans = Math.max(ans, curr[j]);
            }
            int[] t = prev;
            prev = curr;
            curr = t;
        }
        return ans;
    }
}
