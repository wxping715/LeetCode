class Solution {
    
    // Map + Set solution
//     public List<String> findAndReplacePattern(String[] words, String pattern) {
//         List<String> ans = new ArrayList();
//         for (String word : words) {
//             if (check(word, pattern))
//                 ans.add(word);
//         }
//         return ans;
//     }
    
//     private boolean check(final String word, final String pattern) {
//         if (word.length() != pattern.length()) return false;
//         Map<Character, Character> map = new HashMap<>();
//         Set<Character> set = new HashSet<>();
//         // word -> pattern
//         for (int i = 0; i < word.length(); i++) {
//             char chp = pattern.charAt(i);
//             char chw = word.charAt(i);
//             if (map.containsKey(chp)) {
//                 if (map.get(chp) != chw) return false;
//             } else {
//                 if (set.contains(chw)) return false;
//                 map.put(chp, chw);
//                 set.add(chw);
//             }
            
//         }
//         return true;
//     }
    
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList();
        int[] encodedPattern = encode(pattern);
        for (String word : words) {
            int[] encodedWord = encode(word);
            if (Arrays.equals(encodedPattern, encodedWord))
                ans.add(word);
        }
        return ans;
    }
    
    private int[] encode(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int[] result = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            map.computeIfAbsent(s.charAt(i), key -> map.size());
            result[i] = map.get(s.charAt(i));
        }
        return result;
    }
}
