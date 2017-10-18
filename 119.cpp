/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        
        vector<vector<int>> result;
        result.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            vector<int> cur(i, 0);
            for (int j = 0; j < i; j++) {
                if (j == 0) cur[j] = result[i-2][j];
                else if (j == i-1) cur[j] = result[i-2][j-1];
                else cur[j] = result[i-2][j] + result[i-2][j-1];
            }
            result.push_back(cur);
        }
        return result;
    }
};
