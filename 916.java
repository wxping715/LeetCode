/*
We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

 
*/

class Solution {
    
    // O(max(m,n)*26)
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] counterB = new int[26];
        for (int i = 0; i < B.length; i++)  {
            int[] count = counter(B[i]);
            for (int j = 0; j < 26; j++) {
                counterB[j] = Math.max(counterB[j], count[j]);
            }
        }
        List<String> result = new ArrayList<>();
        for (String s : A) {
            int[] counterA = counter(s);
            if (isSubset(counterA, counterB)) result.add(s);
        }
        return result;
    }
    
    private boolean isSubset(int[] counterA, int[] counterB) {
        for (int i = 0; i < 26; i++) {
            if (counterA[i] < counterB[i])
                return false;
        }
        return true;
    }
    
    private int[] counter(String s) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        return count;
    }
}
