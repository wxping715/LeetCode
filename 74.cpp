/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    
    // extended binary search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n < 1) return false;
        
        int m = matrix[0].size();
        if(m < 1) return false;
        
        int f = 0, r = n*m-1, mid;
        while(f <= r){
            mid = (f+r)/2;
            int val = matrix[mid/m][mid-m*(mid/m)];
            
            if(val == target) return true;
            else if(val < target) f = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
