int findMin(int num[], int n) {
    
    if(n == 1) return num[0];
    if(n == 2) return num[0]<num[1] ? num[0] : num[1];
    
    int f = 0,r = n - 1,mid;
    
    while(f < r){
        mid = (f+r) / 2;
        
        if(num[f] > num[mid] && num[mid] > num[r]) return num[r];
        else if(num[f] < num[mid] && num[mid] < num[r]) return num[f];
        
        if(num[f] > num[mid]) r = mid;
        else if(num[f] < num[mid]) f = mid;
        else return num[f] < num[r] ? num[f] : num[r];
    }
    return num[f];
}