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
