int max(int a,int b){  return a > b ? a : b; }

int rob(int num[], int n) {
    
    if(n == 0) return 0;
    if(n == 1) return num[0];
    if(n == 2) return num[1] > num[0] ? num[1] : num[0];
    
    int dp[n];
    
    dp[0] = num[0];
    dp[1] = num[1] > num[0] ? num[1] : num[0];
    
    for(int i = 2;i < n;i++)
        dp[i] = max(dp[i-2]+num[i],dp[i-1]);
    
    return dp[n-1];
}