class Solution {
    int[] ax = new int[]{-1, 0, 1, 0};
    int[] ay = new int[]{0, 1, 0, -1}; 
    public int numDistinctIslands(int[][] grid) {
        if (grid == null || grid.length == 0) 
            return 0;
        Set<String> islands = new HashSet<>();
        int ans = 0;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                StringBuilder sb = new StringBuilder();
                dfs(grid, i, j, sb, 'o');
                String island = sb.toString();
                //System.out.println(island);
                if (!islands.contains(island))
                    ans++;
                islands.add(island);
            }
        return ans;
    }
    
    void dfs(int[][] grid, int x, int y, StringBuilder sb, char start) {
        grid[x][y] = 0;
        sb.append(start);
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < 4; i++) {
            int nx = x + ax[i], ny = y + ay[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0)
                continue;
            char dir = ' ';
            if (i == 0) dir = 'u';
            else if (i == 1) dir = 'r';
            else if (i == 2) dir = 'd';
            else dir = 'l';
            dfs(grid, nx, ny, sb, dir);
            sb.append('b');
        }
    }
}
