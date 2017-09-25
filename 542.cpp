/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) q.emplace(i,j);
                else matrix[i][j] = INT_MAX;
            }
        
        int ax[4] = {0, -1, 0, 1};
        int ay[4] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = ax[i] + cur.first;
                int c = ay[i] + cur.second;
                
                if (r < 0 || r >= n || c < 0 || c >= m ||
                   matrix[r][c] <= matrix[cur.first][cur.second])
                    continue;
                q.emplace(r, c);
                matrix[r][c] = matrix[cur.first][cur.second] + 1;
            }
        }
        return matrix;
    }
};
