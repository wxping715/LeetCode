/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    
    // dp solution
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 0), cur(n, 0);
        cur[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i+j == 0) continue;
                
                if (i-1 >= 0) cur[j] += pre[j];
                if (j-1 >= 0) cur[j] += cur[j-1];
            }
            pre = cur;
            fill(cur.begin(), cur.end(), 0);
        }
        return pre[n-1];
    }
    
    // math solution
    // C(m+n-2, m-1)
    int uniquePaths(int m, int n) {
        
    }
};
