class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.length() < 2) return res;
        for (int i = 0; i+1 < s.length(); i++) {
            if ((s[i] != s[i+1]) || (s[i] == '-')) continue;
            // cout << s[i] << endl;
            string ns(s.begin(), s.end());
            // cout << ns << endl;
            ns[i] = '-';
            ns[i+1] = '-';
            // cout << ns << endl;
            res.push_back(ns);
        }
        
        return res;
    }
};
