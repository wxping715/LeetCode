/**
917. Reverse Only Letters
Easy

227

24

Favorite

Share
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
**/

class Solution {
    public String reverseOnlyLetters(String S) {
        final char[] chars = S.toCharArray();
        int l = 0, r = S.length() - 1;
        while (l < r) {
            if (isLetter(chars[l]) && isLetter(chars[r])) {
                char tmp = chars[l];
                chars[l] = chars[r];
                chars[r] = tmp;
                l++; r--;
            } else if (!isLetter(chars[l])) {
                l++;
            } else {
                r--;
            }
        }
        
        return String.valueOf(chars);
    }
    
    private boolean isLetter(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
}
