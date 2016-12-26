/*You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
        
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int times = 0, mindist;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mindist = -1;
                    auto dist = grid;
                    queue<pair<int,int>> q;
                    q.emplace(i,j);
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int x = cur.first+ax[d], y = cur.second+ay[d];
                            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == times) {
                                grid[x][y]--;
                                dist[x][y] = dist[cur.first][cur.second]+1;
                                total[x][y] += dist[x][y]-1;
                                q.emplace(x, y);
                                if (mindist < 0 || mindist > total[x][y])
                                    mindist = total[x][y];
                            }
                        }
                    }
                    times--;
                }
            }
        return mindist;
    }
};
