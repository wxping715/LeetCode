class Solution {
    public List<String> commonChars(String[] A) {
        int[] chars = new int[26];
        int[] totalChars = new int[26];
        Arrays.fill(totalChars, Integer.MAX_VALUE);
        for (String str : A) {
            for (int i = 0; i < str.length(); i++) {
                chars[str.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                totalChars[i] = Math.min(totalChars[i], chars[i]);
                chars[i] = 0;
            }
        }
        
        List<String> res = new ArrayList();
        for (int i = 0; i < 26; i++) {
            while ((totalChars[i]--) > 0) {
                res.add(String.valueOf((char)('a' + i)));
            }
        }
        return res;
    }
}
