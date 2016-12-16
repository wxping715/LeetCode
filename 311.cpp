/*Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |*/

class Solution {
public:

    // my initial solution 162ms
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int m1, n1, m2, n2;
        if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0) return res;
        m1 = A.size(); n1 = A[0].size(); m2 = B.size(); n2 = B[0].size();
        
        vector<int> rzeros, czeros;
        for (int i = 0; i < m1; i++) {
            bool all = true;
            for (int j = 0; j < n1; j++) {
                if (A[i][j] != 0) {
                    all = false;
                    break;
                }
            }
            rzeros.push_back(all ? 1 : 0);
        }
    
        for (int i = 0; i < n2; i++) {
            bool all = true;
            for (int j = 0; j < m2; j++) {
                if (B[j][i] != 0) {
                    all = false;
                    break;
                }
            }
            czeros.push_back(all ? 1 : 0);
        }
        
        for (int i = 0; i < m1; i++) {
            res.push_back(vector<int>());
            for (int j = 0; j < n2; j++) {
                int val = 0;
                if (!rzeros[i] || !czeros[j]) {
                    for (int k = 0; k < n1; k++)
                        val += A[i][k] * B[k][j];
                }
                res[i].push_back(val);
            }
        }
        return res;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int m1, n1, m2, n2;
        if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0) return res;
        m1 = A.size(); n1 = A[0].size(); m2 = B.size(); n2 = B[0].size();
        res = vector<vector<int>>(m1, vector<int>(n2, 0));
        for (int i = 0; i < m1; i++)
            for (int k = 0; k < n1; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n2; j++)
                    res[i][j] += A[i][k] * B[k][j];
            }
        return res;
    }
};
