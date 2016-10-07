class Solution {
public:

    // use two pointers p1 and p2
    int lengthOfLongestSubstring(string s) {
        int table[256];
        fill(table, table+256,-1);
        
        int p1 = 0, p2 = 0, res = 0;
        while (p2 < s.length()) {
            char ch = s[p2];
            if (table[ch] != -1) {
                res = max(p2-p1, res);
                int i;
                for (i = p1; i <= table[ch]; i++)
                    table[s[i]] = -1;
                p1 = i;
            } 
            table[ch] = p2++;
        }
        res = max(p2-p1, res);
        return res;
    }
};
