/*A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the two dimension case?
Show Company Tags
Show Tags
Show Similar Problems*/


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xs, ys;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == 1) {
                    xs.push_back(i);
                    ys.push_back(j);
                }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        
        if (xs.empty()) return 0;
        int x = xs[xs.size()/2], y = ys[ys.size()/2];
        
        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    ret += abs(i-x) + abs(j-y);
                }
        return ret;
    }
};
