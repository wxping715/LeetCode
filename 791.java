/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
*/

class Solution {
    public String customSortString(String S, String T) {
        int[] counter = new int[26];
        for (int i = 0; i < T.length(); i++)
            counter[T.charAt(i) - 'a']++;
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            int index = S.charAt(i) - 'a';
            while (counter[index] > 0) {
                sb.append((char)('a' + index));
                counter[index]--;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            while (counter[i] > 0) {
                sb.append((char)(i+'a'));
                counter[i]--;
            }
        }
        return sb.toString();
    }
}
