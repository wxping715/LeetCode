/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].

*/

class Solution {
public:
    
    // O(2*m*n) space, O(4*m*n*N) time
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> pre(m, vector<int>(n, 0)), cur(m, vector<int>(n, 0));
        pre[i][j] = 1;
        const int MOD = 1000000007;
        
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
    
        int res = 0;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (!pre[i][j]) continue;
                    for (int l = 0; l < 4; l++) {
                        int nx = ax[l] + i, ny = ay[l] + j;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            res = (res + pre[i][j]) % MOD;
                        else
                            cur[nx][ny] = (cur[nx][ny] + pre[i][j]) % MOD;
                    }
                }
            pre = cur;
            // set all numbers in cur as 0
            std::fill(cur.begin(), cur.end(), vector<int>(n, 0));
        }
        
        return res;
    }
};
