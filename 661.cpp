/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/

class Solution {
public:
    
    /*
    * take two vectors to cache the computed results in turn
    */
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty()) return M;
        int m = M.size();
        if (M[0].empty()) return M;
        int n = M[0].size();
        
        vector<vector<int>> cache(2, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = 0, c = 0;
                for (int k = -1; k <= 1; k++)
                    for (int r = -1; r <= 1; r++) {
                        int v = getIndex(M, m, n, i+k, j+r);
                        if (v == -1) continue;
                        s += v;
                        c++;
                    }
                cache[i%2][j] = s/c;
            }
            
            // overwite i-1
            if (i-1 < 0) continue;
            for (int j = 0; j < n; j++)
                M[i-1][j] = cache[(i-1)%2][j];
        }
        
        // overwrite the last row
        for (int j = 0; j < n; j++)
            M[m-1][j] = cache[(m-1)%2][j];
        
        return M;
    }
    
    int getIndex(vector<vector<int>>& M, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return -1;
        return M[i][j];
    }
};
