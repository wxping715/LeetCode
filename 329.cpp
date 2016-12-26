class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        if (matrix[0].empty()) return 0;
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int maxv = search(matrix, dp, i, j, INT_MIN);
                res = max(maxv, res);
            }
        return res;
    }
    
    int search(vector<vector<int>> &matrix, vector<vector<int>>& dp, int i, int j, int pre) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= pre)
            return 0;
        
        if (dp[i][j] > 0) return dp[i][j];
        
        int cur = matrix[i][j], maxv = 0;
        maxv = max(search(matrix, dp, i+1, j, matrix[i][j]), maxv);
        maxv = max(search(matrix, dp, i-1, j, matrix[i][j]), maxv);
        maxv = max(search(matrix, dp, i, j+1, matrix[i][j]), maxv);
        maxv = max(search(matrix, dp, i, j-1, matrix[i][j]), maxv);
        
        dp[i][j] = maxv+1;
        return dp[i][j];
    }
};
