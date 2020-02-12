/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.

 

Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
Example 2:

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 3:

Input: A = [1,2,4], K = 3
Output: 6
Explanation: 
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
 

Note:

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/
class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        int missingCount = (nums[n-1]-nums[0]+1)-n;
        if (missingCount < k) {
            return nums[n-1]+k-missingCount;
        }
        
        int l = 0, r = n-1;
        // find the first equal or greater 
        while (l < r) {
            int m = (r-l)/2+l;
            int missing = nums[m]-nums[0]-m;
            if (missing < k) l = m+1;
            else r = m;
        }
        System.out.println(l);
        return nums[0]+k+l-1;
    }
}
