/*Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rows(m, vector<int>(n,0));
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            int ecnt, j = 0, sj;
            while (j < n) {
                ecnt = 0; sj = j;
                while (j < n && grid[i][j] != 'W') {
                    if (grid[i][j] == 'E') ecnt++;
                    j++;
                }
                for (int k = sj; k < j; k++)
                    if (grid[i][k] != 'E')
                        rows[i][k] = ecnt;
                // skip the wall 
                j++;
            }
        }
        
        for (int j = 0; j < n; j++) {
            int ecnt, i = 0, si;
            while (i < m) {
                ecnt = 0; si = i;
                while (i < m && grid[i][j] != 'W') {
                    if (grid[i][j] == 'E') ecnt++;
                    i++;
                }
                
                for (int k = si; k < i; k++) 
                    if (grid[k][j] != 'E')
                        res = max(res, rows[k][j]+ecnt);
                i++;
            }
        }
        
        return res;
    }
};
