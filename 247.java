class Solution {
    public List<String> findStrobogrammatic(int n) {
        return generate(n,n);
    }
    
    private List<String> generate(int n, int m) {
        if (n == 0) return new ArrayList<String>(Arrays.asList(""));
        if (n == 1) return new ArrayList<String>(Arrays.asList("0", "1", "8"));
        
        List<String> subResult = generate(n-2, m);
        List<String> results = new ArrayList<>();
        
        for (String r : subResult) {
            if (n != m) results.add("0"+r+"0");
            results.add("1"+r+"1");
            results.add("6"+r+"9");
            results.add("8"+r+"8");
            results.add("9"+r+"6");
        }
        return results;
    }
}
