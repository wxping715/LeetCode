/*
Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
*/

class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        return Math.max(compute(A, L, M), compute(A, M, L));
    }
    
    
    /*
    [0,6,5,2,2,5,1,9,4], L = 1, M = 2
    mmax = 0, 13, 13, 13, 13, 13, 13, 13             
    */
    public int compute(int[] A, int L, int M) {
        // max subarray starting with i
        int[] mmax = new int[A.length];
        int max = 0, sum = 0;
        for (int i = A.length-1; i >= L; i--) {
            sum += A[i];
            if (i + M < A.length) {
                sum -= A[i+M];
            }
            max = Math.max(max, sum);
            mmax[i] = max;
        }
        
        max = 0; sum = 0; 
        int res = 0;
        // i is the end of L subarray, so i+1+M <= A.length
        for (int i = 0; i + M < A.length; i++) {
            sum += A[i];
            if (i - L >= 0) {
                sum -= A[i-L];
            }
            // valid subarray, [i-L+1, i], m subarray at least starting with i+1
            if (i+1 >= L) {
                res = Math.max(res, sum + mmax[i+1]);
            }
        }
        return res;
    }
}
