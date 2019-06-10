class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if (A == null || A.length == 0 || A[0].length == 0) return A;
        int m = A.length, n = A[0].length;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int t = A[i][r];
                A[i][r] = 1 - A[i][l];
                A[i][l] = 1 - t;
                l++; r--;
            }
        }
        return A;
    }
}
