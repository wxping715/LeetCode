/*
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation: 
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.

Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4

Explanation: 
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
*/
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length, m = bikes.length;
        int[][] dp = new int[n+1][(1 << m)];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < (1<<m); j++)
                dp[i][j] = Integer.MAX_VALUE;
        
        dp[0][0] = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < (1 << m); s++)
                for (int j = 0; j < m; j++) {
                    if ((s & (1 << j)) == 0)
                        continue;
                    int prev = s ^ (1 << j);
                    if (dp[i-1][prev] != Integer.MAX_VALUE) {
                        dp[i][s] = Math.min(dp[i-1][prev] + dis(workers[i-1], bikes[j]), dp[i][s]);
                    }
                    
                    if (i == n)
                        min = Math.min(dp[i][s], min);
                }
        }
        return min;
    }
    
    private int dis(int[] p1, int[] p2) {
        return Math.abs(p1[0]-p2[0]) + Math.abs(p1[1]-p2[1]);
    }
}
