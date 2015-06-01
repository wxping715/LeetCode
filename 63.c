int get_cell(int** obstacleGrid, int i, int j){
    return *(*(obstacleGrid+i)+j);
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    
    int m = obstacleGridRowSize, n = obstacleGridColSize;
    int** grid = obstacleGrid;
    
    if(m == 0 || n == 0) return 0;
    if(get_cell(grid,0,0) == 1) return 0;
    
    int dp[m][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++){
            if(i+j == 0)  continue;
            if(get_cell(grid,i,j) == 1){
                dp[i][j] = 0;
                continue;
            }
            
            if(i-1 >= 0) dp[i][j] += dp[i-1][j];
            if(j-1 >= 0) dp[i][j] += dp[i][j-1];
        }
    return dp[m-1][n-1];
}
