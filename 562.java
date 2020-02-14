/*
562. Longest Line of Consecutive One in Matrix
Medium

237

63

Add to List

Share
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
    public int longestLine(int[][] M) {
        if (M == null || M.length == 0 || M[0].length == 0)
            return 0;
        
        int m = M.length, n = M[0].length;
        int rowMax = 0, ans = 0;
        int[] colMax = new int[n], diagonal1Max = new int[m+n-1], diagonal2Max = new int[m+n-1];
        for (int i = 0; i < m; i++) {
            rowMax = 0;
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    rowMax++;
                    colMax[j]++;
                    diagonal1Max[i-j+n-1]++;
                    diagonal2Max[i+j]++;
                }
                else {
                    rowMax = 0;
                    colMax[j] = 0;
                    diagonal1Max[i-j+n-1] = 0;
                    diagonal2Max[i+j] = 0;
                }
                ans = Math.max(ans, rowMax);
                ans = Math.max(ans, colMax[j]);
                ans = Math.max(ans,  diagonal1Max[i-j+n-1]);
                ans = Math.max(ans,  diagonal2Max[i+j]);
            }
        }
        return ans;
    }
}
