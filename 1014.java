/*
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.

The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
*/

class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int n = A.length;
        // A[j] - j, while i < j
        int maxv = Integer.MIN_VALUE;
        int res = Integer.MIN_VALUE;
        for (int i = n-1; i >= 0; i--) {
            if (maxv != Integer.MIN_VALUE) {
                res = Math.max(res, A[i] + i + maxv);
            }
            maxv = Math.max(A[i] - i, maxv);
        }
        return res;
    }
}
