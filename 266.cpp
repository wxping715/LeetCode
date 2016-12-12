class Solution {
public:
    bool canPermutePalindrome(string s) {
        int hash[256] = {0};
        for (char ch : s) 
            hash[ch]++;
        
        bool odd = false;
        for (int i = 0; i < 256; i++) {
            if (hash[i]&1) {
                if (!odd) odd = true;
                else return false;
            }
        }
        return true;
    }
};
