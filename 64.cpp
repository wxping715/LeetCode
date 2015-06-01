class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
       
       int m = grid.size();
       if(m < 1) return 0;
       
       int n = grid[0].size();
       if(n < 1) return 0;
       
       int dp[m][n];
       
       dp[0][0] = grid[0][0];
       for(int i = 0;i < m;i++)
           for(int j = 0;j < n;j++)
           {
               if(i+j == 0) continue;
               
               dp[i][j] = 0x3f3f3f3f;
               if(i - 1 >= 0) dp[i][j] = dp[i-1][j];
               if(j - 1 >= 0) dp[i][j] = dp[i][j-1] > dp[i][j] ? dp[i][j] : dp[i][j-1];
               
               dp[i][j] += grid[i][j];
           }
           
        return dp[m-1][n-1];
    }
};
