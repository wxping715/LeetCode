class Solution {
public:

    // O(m+n) Space
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;
        
        vector<int> zero_rows(matrix.size(), 0), zero_cols(matrix[0].size(), 0);
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zero_rows[i] = 1;
                    zero_cols[j] = 1;
                }
            }
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; zero_rows[i] == 1 && j < matrix[0].size(); j++)
                matrix[i][j] = 0;
        for (int j = 0; j < matrix[0].size(); j++)
            for (int i = 0; zero_cols[j] == 1 && i < matrix.size(); i++)
                matrix[i][j] = 0;
    }
    
    // O(1) Space
    /*
    * using the first elem in each row to store this row's status
    * using the first elem in each column to store this column's status
    * bacause matrix[0][0] can only store one status, so use col0 to store 0-th cols' status
    */
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;
        
        int col0 = 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) 
                    matrix[i][0] = matrix[0][j] = 0;
        }
        
        for (int i = matrix.size()-1; i >= 0; i--) {
            for (int j = matrix[0].size()-1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};
