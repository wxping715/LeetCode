class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();        
        vector<int> pre(n, 0), cur(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) cur[j] = 0;
                else cur[j] = INT_MAX;
                
                if (i > 0) cur[j] = pre[j];
                if (j > 0) cur[j] = min(cur[j], cur[j-1]);
                cur[j] += grid[i][j];
                
                // cout << i << " " << j << " " << cur[j] <<endl;
            }
            pre = cur;
        }
        
        return pre[n-1];
    }
};
