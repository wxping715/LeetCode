/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return true;
        
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                if (check(s, l+1, r) || check(s, l, r-1))
                    return true;
                return false;
            }
            l++; r--;
        }
        return true;
    }
    
    bool check(string& s, int l, int r) {
        int i = l, j = r;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
