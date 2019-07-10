// [10, 5], [10], [5,2,6], [5,2], [5], [2,6], [2],[6]
/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int ans = 0, l = 0, product = 1, n = nums.length;
        for (int r = 0; r < n; r++) {
            product *= nums[r];
            while (l <= r && product >= k) product /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
}
