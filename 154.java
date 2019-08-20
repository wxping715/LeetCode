class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1, m;
        while (l < r) {
            m = (r-l)/2 + l;
            if (nums[m] > nums[r]) l = m + 1;
            else if (nums[m] < nums[r]) r = m;
            // 0 1 2 3 3 3 3
            // 3 3 3 3 2 1 0 
            else r--;
        }
        return nums[l];
    }
}
