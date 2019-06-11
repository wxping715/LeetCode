class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> hashmap = new HashMap<Integer, Integer>();
        for (int x : deck) hashmap.put(x, hashmap.getOrDefault(x, 0) + 1);
    
        int gcd = 0;
        for (Map.Entry<Integer, Integer> entry : hashmap.entrySet()) {
            gcd = gcd(gcd, entry.getValue());
        }
        return gcd >= 2;
    }
    
    //12, 16
    private int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
}
