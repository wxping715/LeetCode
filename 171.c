char ans[20];
char *convertToTitle(int n) {
    
    //char ans[20];
    int cnt = 0;
    
    while(n){
       ans[cnt] = n % 26 + 'A' - 1;
       if(ans[cnt] < 'A') ans[cnt] += 26;
       
       cnt++;
       if(n % 26 == 0) n--;
       n /= 26;
    }
    
    for(int i = 0;i <= (cnt-1)/2;i++)
    {
        char tmp = ans[i];
        ans[i] = ans[cnt-1-i];
        ans[cnt-1-i] = tmp;
    }
    
    return ans;
}