/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1, m;
        while (l < r) {
            m = (r-l)/2 + l;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
}
