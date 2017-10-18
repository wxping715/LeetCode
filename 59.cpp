/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0, down = n-1, left = 0, right = n-1, current = 0;
        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++)
                matrix[top][i] = ++current;
            top++;
            
            for (int i = top; i <= down; i++)
                matrix[i][right] = ++current;
            right--;
            
            if (top <= down)
                for (int i = right; i >= left; i--)
                    matrix[down][i] = ++current;
            down--;
            
            if (left <= right)
                for (int i = down; i >= top; i--)
                    matrix[i][left] = ++current;
            left++;
        }
        
        return matrix;
    }
};
