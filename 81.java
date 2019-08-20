class Solution {
    public boolean search(int[] nums, int target) {
        int l = 0, r = nums.length - 1, m;
        while (l <= r) {
            m = (r-l)/2 + l;
            if (nums[m] == target) return true;
            if (nums[m] < nums[r]) {
                if (target > nums[r] || target < nums[m]) r = m - 1;
                else l = m + 1;
            } else if (nums[m] > nums[r]) {
                if (target > nums[m] || target < nums[l]) l = m + 1;
                else r = m - 1;
            } else if (nums[m] == nums[r]) {
                r--;
            }
        }
        return false;
    }
}
