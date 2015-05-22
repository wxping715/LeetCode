int mySqrt(int x) {
    
    int f = 0, r = 46340,mid;
    
    if( x > r * r) return r;
    
    while(f < r){

        mid = (f+r)/2;

        if(mid*mid <= x){
            if((mid+1)*(mid+1) > x) return mid;
            else f = mid + 1;
        }else{
            if((mid-1)*(mid-1) <= x) return mid-1;
            else r = mid-1;
        }
    }
}
