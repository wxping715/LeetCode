class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
        
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    if (i+ax[k] < 0 || i+ax[k] >= m ||
                        j+ay[k] < 0 || j+ay[k] >= n ||
                        grid[i+ax[k]][j+ay[k]] == 0)
                        res++;
                }
                // cout << i << " " << j << res << endl;
            }
        return res;
    }
};
