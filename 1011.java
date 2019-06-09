class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int sum = 0, max = 0;
        for (int w : weights) {
            sum += w;
            max = Math.max(max, w);
        }
        
        int l = Math.max(sum%D == 0 ? sum/D : sum/D + 1, max);
        int r = sum;
        while (l < r) {
            int m = (r+l)/2;
            if (!check(weights, D, m)) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    private boolean check(int[] weights, int D, int size) {
        int days = 0, sum = 0;
        for (int w : weights) {
            if (sum + w > size) {
                days += 1;
                sum = 0;
            }
            sum += w;
        }
        if (sum > 0) {
            days++;
        }
        return days <= D;
    }
}
