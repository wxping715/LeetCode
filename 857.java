/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.
*/

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i][0] = 1.0 * wage[i] / quality[i];
            workers[i][1] = quality[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> pq = new PriorityQueue<>();
        double ans = Double.MAX_VALUE;
        int pqsum = 0;
        for (int i = 0; i < n; i++) {
            double[] worker = workers[i];
            pqsum += worker[1];
            pq.offer(-worker[1]);
            
            if (pq.size() >= K) {
                if (pq.size() > K) pqsum += pq.poll();
                ans = Math.min(pqsum*worker[0], ans);
            }
        }
        return ans;
    }
}
