/*
We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for (int num : nums) {
            int v = map.getOrDefault(num, 0);
            map.put(num, v+1);
            ans = Math.max(ans, Math.max(map.getOrDefault(num-1, -(v+1)), map.getOrDefault(num+1, -(v+1))) + v+1);
        }
        return ans;
    }
}
