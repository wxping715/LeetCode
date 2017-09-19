class Solution {
public:
    
    bool check(int d[256], int c[256]) {
        for (int i = 0; i < 256; i++)
            if (d[i] > c[i]) {
                return false;
            }
        return true;
    }
    
    string minWindow(string s, string t) {  
        int d[256] = {0}, c[256] = {0};
        for (char ch : t)
            d[ch]++;
        
        int l = 0, r = -1, ml, mr, minl = s.size()+1;
        while (r < (int)s.length()) {
            if (check(d, c)) {
                if (r-l+1 < minl) {
                    ml = l;
                    mr = r;
                    minl = r-l+1;
                }
                c[s[l++]]--;
            } else {
                if (++r < s.length())
                    c[s[r]]++;
            }
        }
        
        return minl == s.size()+1 ? "" : s.substr(ml, mr-ml+1);
    }
};
