/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
*/

class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = 1000000;
        while (l < r) {
            int m = (l + r) / 2;
            if (count(nums, m) < k) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    private int count(int[] nums, int k) {
        int ans = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            while (j < nums.length && nums[j] - nums[i] <= k) j++;
            ans += j - i - 1;
        }
        return ans;
    }
}
