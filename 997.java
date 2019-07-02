class Solution {
    public int[] sortedSquares(int[] A) {
        int[] ans = new int[A.length];
        int l = 0, r = A.length - 1, i = A.length - 1;
        while (l <= r) {
            ans[i--] = Math.abs(A[l]) > Math.abs(A[r]) ? A[l] * A[l++] : A[r] * A[r--];
        }
        return ans;
    }
}
