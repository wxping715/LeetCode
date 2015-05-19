bool isPalindrome(int x) {
    
    if(x < 0) return false;
    
    int ret = 0, t = x;
    while(t){
        ret = ret * 10 + t % 10;
        t /= 10;
    }
    
    return ret == x;
}