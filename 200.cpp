class Solution {
public:
    
    int ax[4] = {-1, 0, 1, 0};
    int ay[4] = {0, 1, 0, -1};
    int m,n;
    
    int numIslands(vector<vector<char>>& grid) {
        // Write your code here
        if (grid.size() < 1)  return 0;
        if (grid[0].size() < 1) return 0;
        
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        int cnt = 0;
        for (int i = 0;i < m;i++)
            for(int j = 0;j < n;j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i,j, visited, grid);
                }
            }
        return cnt;
    }
    
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = 1;
        for(int k = 0; k < 4;k++) {
            int ni = i+ax[k], nj = j+ay[k];
            
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (!visited[ni][nj] && grid[ni][nj] == '1') {
                dfs(ni, nj, visited, grid);
            }
        }
    }
    
    
};
