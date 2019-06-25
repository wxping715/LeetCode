class Solution {
    public int expressiveWords(String S, String[] words) {
        int ans = 0;
        for (String t : words)
            if (check(S, t))
                ans++;
        return ans;
    }
    
    private boolean check(String s, String t) {
        if (s.length() < t.length()) return false;
        int previ = 0, prevj = 0;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            while (i < s.length() && s.charAt(i) == s.charAt(previ)) i++;
            while (j < t.length() && t.charAt(j) == t.charAt(prevj)) j++;
            
            if (s.charAt(previ) != t.charAt(prevj)) return false;
            if (i-previ < j-prevj || (i-previ > j-prevj && i-previ < 3)) return false;
            previ = i;
            prevj = j;
        }
        
        return i == s.length() && j == t.length();
    }
}
