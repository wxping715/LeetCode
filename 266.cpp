/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hashmap;
        for (char ch : s)
            hashmap[ch]++;
        
        int odd = 0;
        for (auto it : hashmap)
            if (it.second & 1)
                odd++;
        
        if (odd <= 1) return true;
        return false;
    }
};
