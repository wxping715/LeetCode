/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    /* 
    * two pointers problem
    * p start from the head of string, q starts from the end of string
    *   1. when p and q are both vowels, the swap p and q;
    *   2. when s[p] or s[q] is not vowels, p++, q--
    */
    string reverseVowels(string s) {
        if (s.length() == 1) return s;
        
        int p = 0, q = s.length()-1;
        while (p <= q) {
            if (isvowel(s[p]) && isvowel(s[q])) {
                char t = s[p];
                s[p] = s[q];
                s[q] = t;
                p++; q--;
            }
            
            if (!isvowel(s[p])) p++;
            if (!isvowel(s[q])) q--;
        }
        return s;
    }
    
    bool isvowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};
