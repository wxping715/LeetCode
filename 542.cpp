class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) q.push(make_pair(i, j));
                else matrix[i][j] = INT_MAX;
            }
        
        int ax[4] = {-1, 0, 1, 0};
        int ay[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = cur.first + ax[i];
                int c = cur.second + ay[i];
                
                if (r < 0 || r >= m || c < 0 || c >= n ||
                    matrix[r][c] <= matrix[cur.first][cur.second]+1)
                    continue;
                q.push(make_pair(r,c));
                matrix[r][c] = matrix[cur.first][cur.second]+1;
            }
        }
        return matrix;
    }
};
