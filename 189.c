void reverse(int nums[],int l,int r)
{
    int tmp;
    for(int i = 0;i <= (r-l)/2;i++){
        tmp = nums[l+i];
        nums[l+i] = nums[r-i];
        nums[r-i] = tmp; 
    }
}

void rotate(int nums[], int n, int k) {
    
    k = k % n;
    if(k == 0) return;
    
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-k-1);
    reverse(nums,0,n-1);
}