class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        int hash[256] = {0}, cur[256] = {0};
        for (char ch : t)
            hash[ch]++;
        
        string ret = s;
        int lidx = 0, cidx = 0;
        bool found = false;
        while (cidx < s.length()) {
            cur[s[cidx]]++;
            if (compare(hash, cur)) {
                found = true;
                while (lidx < cidx && compare(hash, cur)) {
                    //try to move lidx
                    cur[s[lidx]]--;
                    // if failed, restore it
                    if (!compare(hash, cur)) {
                        cur[s[lidx]]++;
                        break;
                    }
                    lidx++;
                }
                ret = ret.length() > cidx-lidx+1 ? s.substr(lidx, cidx-lidx+1) : ret;
            }
            cidx++;
        }
        return found ? ret : "";
    }
    
    bool compare(int hash[256], int cur[256]) {
        for (int i = 0; i < 256; i++)
            if (hash[i] > cur[i]) return false;
        return true;
    }
};
