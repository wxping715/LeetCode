int trailingZeroes(int n) {
    
    int cnt = 0;
    while(n){
        cnt += n / 5;
        n /= 5;
    }
    return cnt;
}
