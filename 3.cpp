/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int l = 0, r = 0, ret = 0;
        while (r < s.length()) {
            if (hash.count(s[r])) hash.erase(s[l++]);
            else hash.insert(s[r++]);
            
            ret = max(r-l, ret);
        }
        return ret;
    }
};
