class Solution {
public:
    string originalDigits(string s) {
        if (s.empty()) return "";
        int cnt[26] = {0};
        for (char ch : s)
            cnt[ch-'a']++;
            
        vector<int> digits(10, 0);
        digits[0] = cnt['z'-'a'];
        digits[2] = cnt['w'-'a'];
        digits[4] = cnt['u'-'a'];
        digits[6] = cnt['x'-'a'];
        digits[8] = cnt['g'-'a'];
        digits[3] = cnt['h'-'a'] - digits[8];
        digits[7] = cnt['s'-'a'] - digits[6];
        digits[1] = cnt['o'-'a'] - digits[2] - digits[4] - digits[0];
        digits[5] = cnt['v'-'a'] - digits[7];
        digits[9] = (cnt['n'-'a'] - digits[1] - digits[7])/2;
        
        string res = "";
        for (int i = 0; i < 10; i++) {
            if (digits[i] > 0) {
                res += string(digits[i], '0'+i);
            }
        }
        return res;
    }
};
