int finditem(int a[],int l,int r,int k){

	int i,j,t,tmp;
	if(l > r) return 0;
	i = l; j = r;t = a[l];
	while(i < j){
		while(a[j] > t && i < j) j--;
		while(a[i] <= t && i < j) i++; 
		if(i < j){
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	a[l] = a[j];
	a[j] = t;

	if(r-j+1 == k) return a[j];
	else if(r-j+1 < k) return finditem(a,l,i-1,k-(r-j+1));
	else return finditem(a,i+1,r,k); 
}

int findKthLargest(int* nums, int numsSize, int k) {
    
    return finditem(nums,0,numsSize-1,k);
    
}
