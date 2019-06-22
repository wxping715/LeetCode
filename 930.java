/*
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

*/

class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        int ans = 0, sum = 0;
        for (int a : A) {
            sum += a;
            if (sum >= S) ans += map.getOrDefault(sum - S, 0);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
