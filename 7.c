int MAX_INT = 0x7fffffff;

int reverse(int x) {
    
    int ret = 0,t = x;
    while(t){
        ret = ret * 10 + t % 10;
        t /= 10;
        
        if((ret > 0 ? ret : -ret) > (MAX_INT / 10) && t) return 0;
    }

    return ret;
}