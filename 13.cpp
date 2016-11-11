class Solution {
public:
    int romanToInt(string s) {
        int hash[128];
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int res;
        if (s.empty()) return 0;
        if (s.length() == 1) return hash[s.front()];
        
        res = hash[s.back()];
        int pre = hash[s.back()];
        for (int i = s.length()-2; i >= 0; i--) {
            // cout << s[i] << " " << res << endl;
            int val = hash[s[i]];
            if (val >= pre) res += val;
            else res -= val;
            
            pre = val;
        }
        return res;
    }
};
