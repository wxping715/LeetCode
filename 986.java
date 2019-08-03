class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> results = new ArrayList<>();
        int i = 0, j = 0, m = A.length, n = B.length;
        while (i < m && j < n) {
            int l = Math.max(A[i][0], B[j][0]);
            int r = Math.min(A[i][1], B[j][1]);
            // no intersection
            if (l <= r) results.add(new int[]{l, r});
            if (r == A[i][1]) i++;
            else j++;
        }
        return results.toArray(new int[results.size()][2]);
    }
}
