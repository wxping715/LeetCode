int searchInsert(int A[], int n, int target) {
    int l = 0,r = n-1,mid;

    while(l <= r){
        mid = (l+r)/2;
        if(A[mid] == target){
            return mid;
        }else if(A[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;
}