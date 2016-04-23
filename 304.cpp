class NumMatrix {
public:
    
    vector<vector<int> > sum;
    int m,n;
    /*
    * dp problem
    * sumRegion(r1, c1, r2, c2) = sum(r2,c2) - sum(r2,c1-1) - sum(r1-1,c2) + sum(r1-1, c1-1);
    * sum(i,j) = sum(i, j-1) + sum(i-1, j) - sum(i-1, j-1) + matrix[i][j];
    */
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        
        if (m <= 0) return;
        n = matrix[0].size();
        
        sum.resize(m);
        fill(sum.begin(), sum.end(), vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                sum[i][j] = get_sum(i, j-1) + get_sum(i-1, j) - get_sum(i-1, j-1) + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2, col2) - get_sum(row2, col1-1) - get_sum(row1-1, col2) + get_sum(row1-1, col1-1);
    }
    
    int get_sum(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        return sum[i][j];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
