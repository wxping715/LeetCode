class Solution {
public:

    string p = {'(', ')'};
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s, 0, 0, 0, res);
        return res;
    }
    
    void remove(string &s, int lasti, int lastj, int rev, vector<string>& res) {
        int cnt = 0;
        for (int i = lasti; i < s.length(); i++) {
            if (s[i] == p[rev]) cnt++;
            else if (s[i] == p[1-rev]) cnt--;
            if (cnt < 0) {
                for (int j = lastj; j <= i; j++) {
                    if (s[j] == p[1-rev] && (j == lastj || s[j-1] != p[1-rev])) {
                        string ns = s.substr(0, j) + s.substr(j+1);
                        remove(ns, i, j, rev, res);
                    }
                }
                return;
            }
        }
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (p[rev] == '(')
            remove(rs, 0, 0, 1-rev, res);
        else
            res.push_back(rs);
    }
};
