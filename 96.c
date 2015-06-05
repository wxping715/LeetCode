int numTrees(int n) {
    if(n == 0) return 0;
    
    int f[1000];
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        int ans = 0;
        for(int j = 0;j <= i-1;j++)
            ans += f[j]*f[i-j-1];
        f[i] = ans;
    }
    
    return f[n];
}
