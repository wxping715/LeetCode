int hammingWeight(uint32_t n) {
    int num = 0;
    
    while(n){
        n &= (n-1);
        num++;
    }
    return num;
}