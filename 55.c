int max(int a,int b){
    return a > b ? a : b;
}

bool canJump(int* nums, int numsSize) {
    
    int maxlength = 0;
    for(int i = 0;i < numsSize;i++){
        if(i == numsSize -1) return true;
        
        maxlength = max(maxlength-1,nums[i]);
        
        if(maxlength == 0)  return false;
    }
    return false;
}
