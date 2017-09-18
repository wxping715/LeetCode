/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.length() > s.length()) return res;
        
        int cnts[26] = {0}, cntp[26] = {0};
        for (int i = 0; i < p.length(); i++) {
            cnts[s[i]-'a']++;
            cntp[p[i]-'a']++;
        }
        
        if (check(cnts, cntp)) res.push_back(0);
        for (int i = p.length(); i < s.length(); i++) {
            char ch = s[i-p.length()];
            cnts[ch-'a']--;
            ch = s[i];
            cnts[ch-'a']++;
            
            if (check(cnts, cntp)) res.push_back(i+1-p.length());
        }
        return res;
    }
    
    bool check(int cnts[26], int cntp[26]) {
        for (int i = 0; i < 26; i++) {
            if (cnts[i] != cntp[i]) return false;
        }
        return true;
    }
};
