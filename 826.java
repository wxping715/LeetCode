class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = difficulty[i];
            jobs[i][1] = profit[i];
        }
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = Math.max(maxProfit, jobs[i][1]);
            jobs[i][1] = maxProfit;
        }
        
        int ans = 0;
        for (int i = 0; i < worker.length; i++) {
            int next = binarySearch(jobs, n, worker[i]);
            if (next == 0) continue;
            ans += jobs[next-1][1];
        }
        return ans;
    }
    
    // find the first job with difficulty greater than k
    int binarySearch(int[][] jobs, int n, int k) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (jobs[m][0] <= k) l = m + 1;
            else r = m;
        }
        
        if (l == n-1) return jobs[l][0] > k ? l : l + 1;
        return l;
    }
}
