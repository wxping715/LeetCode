/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> result;
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = 0, d = 0;
        int ax[] = {-1, 1}, ay[] = {1, -1};
        
        for (int i = 0; i < m*n; i++) {
            result.push_back(matrix[row][col]);
            row += ax[d];
            col += ay[d];
            
            if (row >= m) { row = m-1; col += 2; d = 1-d;}
            if (col >= n) { col = n-1; row += 2; d = 1-d;}
            if (row < 0)  { row = 0; d = 1-d;}
            if (col < 0)  { col = 0; d = 1-d;}
        }
        return result;
    }
};
