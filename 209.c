int minSubArrayLen(int s, int* nums, int numsSize) {
    int left = 0, right = 0, sum = 0, res = 0x3f3f3f3f;
    while(right < numsSize){
        sum += nums[right++];
        while(sum >= s){
            res = res > right - left? right - left: res;
            sum -= nums[left++];
        }
    }
    return res > numsSize ? 0 : res;
}
