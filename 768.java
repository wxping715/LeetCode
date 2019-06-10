class Solution {
    // sliding window, compare set
    public int maxChunksToSorted(int[] arr) {
        int[] sorted = Arrays.copyOf(arr, arr.length);
        Arrays.sort(sorted);
        
        int res = 0;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            m1.put(arr[i], m1.getOrDefault(arr[i], 0) + 1);
            m2.put(sorted[i], m2.getOrDefault(sorted[i], 0) + 1);
            if (compareMap(m1, m2)) {
                m1.clear();
                m2.clear();
                res++;
            }
        }
        return res;
    }
    
    private boolean compareMap(Map<Integer, Integer> m1, Map<Integer, Integer> m2) {
        if (m1.size() != m2.size()) return false;
        for (Map.Entry<Integer, Integer> entry : m1.entrySet()) {
            int v2 = m2.getOrDefault(entry.getKey(), 0);
            if (entry.getValue() != v2) {
                return false;
            }
        }
        return true;
    }
}
