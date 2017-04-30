class Solution {
public:

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        
        // search left and right bound
        for (int i = 0; i < m; i++) {
            dfs(matrix, pacific, i, 0, INT_MIN);
            dfs(matrix, atlantic, i, n-1, INT_MIN);
        }
        
        //search up and bottom bound
        for (int i = 0; i < n; i++) {
            dfs(matrix, pacific, 0, i, INT_MIN);
            dfs(matrix, atlantic, m-1, i, INT_MIN);
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    res.emplace_back(i, j);
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, int pre) {
        int m = matrix.size(), n = matrix[0].size();
        
        //skip search
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] < pre)
            return;
        visited[x][y] = true;
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            dfs(matrix, visited, x+ax[i], y+ay[i], matrix[x][y]);
        }
    }
};
