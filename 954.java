class Solution {
    public boolean canReorderDoubled(int[] A) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int a : A) map.put(a, map.getOrDefault(a, 0) + 1);
        List<Integer> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);
        
        int firstNonNegativeIndex = keys.size();
        for (int i = 0; i < keys.size(); i++)
            if (keys.get(i) >= 0) {
                firstNonNegativeIndex = i;
                break;
            }
        
        for (int i = firstNonNegativeIndex; i < keys.size(); i++) {
            if (!check(map, keys.get(i)))
                return false;
        }
        
        for (int i = firstNonNegativeIndex-1; i >= 0; i--) {
            if (!check(map, keys.get(i)))
                return false;
        }
        return true;
    }
    
    private boolean check(Map<Integer, Integer> map, int key) {
        int v = map.get(key);
        if (key == 0) return v % 2 == 0;
        
        int v2 = map.getOrDefault(2*key, 0);
        if (v > v2) return false;
        map.remove(key);
        map.put(2*key, v2 - v);
        return true;
    }
}
