void moveZeroes(int* nums, int numsSize) {
    int i = 0, k = 0;
    for (i = 0;i < numsSize;i++)
        if (nums[i] != 0) {
            nums[k++] = nums[i];
            if (i > k - 1)
                nums[i] &= 0;
        }
}
