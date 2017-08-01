/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:

	// O(M*logN)
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int i = 0;i < matrix.size();i++){
//             if(matrix[i].size() < 1) return false;
//             if(target < matrix[i][0]) return false;
//             if(bsearch(matrix[i],target)) return true;
//         }
//         return false;
//     }
    
//     bool bsearch(vector<int> v, int key){
//         int f = 0, r = v.size() - 1,mid;
//         while(f <= r){
//             mid = f+(r-f)/2;
//             if(v[mid] == key) return true;
//             else if(v[mid] < key) f = mid + 1;
//             else r = mid -1;
//         }
//         return false;
//     }
	
	// O(M+N)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix.size();
		if (matrix[0].empty()) return false;
		int n = matrix[0].size();
		
		int i = m-1, j = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] == target) 
				return true;
			else if (matrix[i][j] < target)
				j++;
			else
				i--;
		}
		return false;
	}
};
