/*
767. Reorganize String
Medium

553

28

Favorite

Share
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].

*/

class Solution {
    public String reorganizeString(String S) {
        int[] count = new int[26];
        int maxIndex = 0, sum = 0;
        for (int i = 0; i < S.length(); i++) count[S.charAt(i) - 'a']++;
        for (int i = 0; i < 26; i++) {
            sum += count[i];
            if (count[i] > count[maxIndex]) maxIndex = i;
        }
        
        if (count[maxIndex] > sum - count[maxIndex] + 1) return "";
        
        char[] ans = new char[S.length()];
        int chi = 0, i = maxIndex;
        while (true) {
            while ((count[i]--) > 0) {
                ans[chi] = (char)('a' + i);
                chi += 2;
                if (chi >= ans.length) chi = 1;
            }
            i = (i+1) % 26;
            if (i == maxIndex) break;
        }
        return new String(ans);
    }
}
