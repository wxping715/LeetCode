void reverse(int* nums,int l,int r){
    int tmp, len = r-l+1;
    for(int i = 0;i < len/2;i++){
        tmp = nums[i+l];
        nums[i+l] = nums[len-1-i+l];
        nums[len-1-i+l] = tmp;
    }
}

int search(int* nums, int numsSize, int target) {
   
    if(numsSize == 0) return -1;
    if(numsSize == 1) return nums[0] == target ? 0 : -1;
    
    int pre = nums[0], f = 0, r = numsSize-1, mid,ind = -1;
    for(int i = 1;i < numsSize;i++){
        if(nums[i] < pre){
            ind = i;
            break;
        }else{
            pre = nums[i];
        }
    }
        
    if(ind != -1){
        reverse(nums,0,numsSize-1);
        reverse(nums,0,numsSize-1-ind);
        reverse(nums,numsSize-1-ind+1,numsSize-1);
    }
    
    int res = -1;
    while(f <= r){
        mid = f + (r-f)/2;
        if(nums[mid] == target){
            res = mid;
            break;
        }
        else if(nums[mid]<target) f = mid + 1;
        else r = mid - 1;
    }
    
    if(res == -1) return -1;
    if(ind == -1) return res;
    if(res <= numsSize - 1 - ind)  return res + ind;
    else return res - (numsSize - 1 - ind + 1);
}
