class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        return atMostK(A, K) - atMostK(A, K-1);
    }
    
    public int atMostK(int[] A, int K) {
        Map<Integer, Integer> hashmap = new HashMap<>();
        int ans = 0, l = 0;
        for (int r = 0; r < A.length; r++) {
            hashmap.put(A[r], hashmap.getOrDefault(A[r], 0)+1);
            while (l <= r && hashmap.size() > K) {
                int v = hashmap.get(A[l]);
                if (v > 1) hashmap.put(A[l], v-1);
                else hashmap.remove(A[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
}
