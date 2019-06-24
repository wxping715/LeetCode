/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
*/

class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        
        int[] counter = new int[26];
        boolean swapped = false;
        int firstIndex = -1;
        for (int i = 0; i < A.length(); i++) {
            char charA = A.charAt(i);
            char charB = B.charAt(i);
            
            counter[charA - 'a']++;
            if (charA == charB)
                continue;
            // charA != charB
            if (swapped) return false;
            if (firstIndex == -1) firstIndex = i;
            else {
                swapped = true;
                if (charA == B.charAt(firstIndex) && charB == A.charAt(firstIndex))
                    continue;
                return false;
            }
        }
        
        if (swapped) return true;
        for (int i = 0; i < 26; i++)
            if (counter[i] >= 2)
                return true;
        return false;
    }
}
