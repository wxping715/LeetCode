/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        vector<int> result;
        int top = 0, down = (int) matrix.size()-1, left = 0, right = (int) matrix[0].size()-1;
        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;
            
            for (int i = top; i <= down; i++)
                result.push_back(matrix[i][right]);
            right--;
            
            if (top <= down)
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[down][i]);
                down--;
            
            
            if (left <= right)
                for (int i = down; i >= top; i--)
                    result.push_back(matrix[i][left]);
            left++;
        }
        return result;
    }
};
