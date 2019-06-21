class Solution {
    
    // first version
//     public int maxEqualRowsAfterFlips(int[][] matrix) {
//         int n = matrix.length, m = matrix[0].length;
//         Map<String, Integer> flipCount = new HashMap<>();
//         List<String> zeros = new ArrayList();
//         List<String> ones = new ArrayList();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             zeros.clear();
//             ones.clear();
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) zeros.add(String.valueOf(j));
//                 else ones.add(String.valueOf(j));
//             }
//             String onesString = String.join(",", ones);
//             int count = flipCount.getOrDefault(onesString, 0);
//             flipCount.put(onesString, count + 1);
//             ans = Math.max(ans, count + 1);
            
//             String zerosString = String.join(",", zeros);
//             count = flipCount.getOrDefault(zerosString, 0);
//             flipCount.put(zerosString, count + 1);
//             ans = Math.max(ans, count + 1);   
//         }
//         return ans;
//     }
    
    // optimized
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        Map<String, Integer> flipCount = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int first = matrix[i][0];
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < m; j++) {
                if (first == matrix[i][j]) sb.append(String.valueOf(1));
                else  sb.append(String.valueOf(0));
            }
            String key = sb.toString();
            int count = flipCount.getOrDefault(key, 0);
            flipCount.put(key, count + 1);
            ans = Math.max(ans, count + 1); 
        }
        return ans;
    }
    
}
