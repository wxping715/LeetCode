/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
*/

class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int hash[26] = {0}, current[26] = {0};
        for (char ch : s1)
            hash[ch-'a']++;
        
        int l = 0, r = -1;
        while (r < (int)s2.length()) {
            if (contain(hash, current)) {
                if (r-l+1 == s1.length()) return true;
                current[s2[l++]-'a']--;
            } else {
                r++;
                if (r < s2.length())
                    current[s2[r]-'a']++;
            }
        }
        return false;
    }
    
    bool contain(int hash[26], int current[26]) {
        for (int i = 0; i < 26; i++) 
            if (current[i] < hash[i])
                return false;
        return true;
    } 
};
