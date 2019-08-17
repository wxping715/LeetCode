class Solution {
    int[] ax = new int[]{-1, 0, 1, 0};
    int[] ay = new int[]{0, 1, 0, -1}; 
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) 
            return 0;
    
        int ans = 0;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int size = dfs(grid, i, j);
                ans = Math.max(size, ans);
            }
        return ans;
    }
    
    int dfs(int[][] grid, int x, int y) {
        if (grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int m = grid.length, n = grid[0].length;
        int size = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + ax[i], ny = y + ay[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            size += dfs(grid, nx, ny);
        }
        return size;
    }
}
