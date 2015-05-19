int fac[200];

void init()
{
    fac[0] = 0;
    fac[1] = 1; fac[2] = 2;
    for(int i = 3;i < 200;i++){
        fac[i] = fac[i-1] + fac[i-2];
    }
}

int climbStairs(int n) {
    init();
    return fac[n];
}