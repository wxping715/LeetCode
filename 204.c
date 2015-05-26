int countPrimes(int n) {
    
    bool hash[n];
    
    memset(hash,1,sizeof(hash));
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(hash[i])
        {
            for(int j = 2 * i;j < n;j += i)
                hash[j] = 0;
        }
    }
    
    int res = 0;
    for(int i = 2;i < n;i++)
        if(hash[i])
            res++;
    
    return res;
}
