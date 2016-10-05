class Solution {
public:
    int longestPalindrome(string s) {
        int counter[256] = {0};
        
        for (size_t i = 0; i < s.length(); i++)
            counter[s[i]]++;
        
        int maxl = 0, maxodd = 0;
        for (int i = 0; i < 256; i++) {
            if (counter[i]&1) {
                maxl += counter[i]-1;
                maxodd = 1;
            } else {
                maxl += counter[i];
            }
        }
        return maxl + maxodd;
    }
};
