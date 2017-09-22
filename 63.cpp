/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    
    // dp solution
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        
        vector<int> pre(n, 0), cur(n, 0);
        cur[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                
                if (i-1 >= 0) cur[j] += pre[j];
                if (j-1 >= 0) cur[j] += cur[j-1];
            }
            pre = cur;
            fill(cur.begin(), cur.end(), 0);
        }
        return pre[n-1];
    }
};
