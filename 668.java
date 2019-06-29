class Solution {
    public int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r)/2;
            if (count(m, n, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    private int count(int m, int n, int v) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            // how many elements is smaller than i
            count += Math.min(v/i, n);
        }
        return count;
    }
}
