class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0)
            return 0;
        Queue<int[]> queue = new LinkedList<>();
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    queue.offer(new int[]{i, j, 0});
        
        int ans = 0;
        int[] ax = new int[]{1, 0, -1, 0};
        int[] ay = new int[]{0, 1, 0, -1};
        while (!queue.isEmpty()) {
            int[] poll = queue.poll();
            int x = poll[0], y = poll[1], d = poll[2];
            for (int i = 0; i < 4; i++) {
                int nx = ax[i] + x;
                int ny = ay[i] + y;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[nx][ny] == 1 || -grid[nx][ny] > d+1) {
                    ans = Math.max(d+1, ans);
                    grid[nx][ny] = -(d+1);
                    queue.offer(new int[]{nx, ny, d+1});
                }
            }
        }                
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    return -1;
        return ans;
    }
}
