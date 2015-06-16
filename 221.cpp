class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m < 1) return 0;
        
        int n = matrix[0].size();
        if(n < 1) return 0;
        
        int r[m][n];
        memset(r,0,sizeof(r));
        
        int maxSize = 0;
        for(int i = 0;i < matrix.size();i++)
            for(int j = 0;j < matrix[0].size();j++){
                r[i][j] = matrix[i][j]-'0';
                if(i > 0 && j > 0 && r[i][j] == 1)
                {
                    r[i][j] += min(r[i-1][j],min(r[i][j-1],r[i-1][j-1]));
                }
                
                maxSize = max(r[i][j],maxSize);
            }
        return maxSize * maxSize;
    }
};
