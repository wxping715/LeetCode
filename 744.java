class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0, r = letters.length - 1;
        while (l < r) {
            int m = (r-l)/2 + l;
            if (letters[m] <= target) l = m + 1;
            else r = m;
        }
        
        return target < letters[l] ? letters[l] : letters[0];
    }
}
