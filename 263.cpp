bool isUgly(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;
    
    int f[] = {2,3,5};
    for(int i = 0;i < 3;i++) {
        while(num % f[i] == 0) num /= f[i];
    }
    return num == 1;
}
