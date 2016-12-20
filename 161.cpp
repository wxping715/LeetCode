/*Given two strings S and T, determine if they are both one edit distance apart.*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if (m > n) return isOneEditDistance(t, s);
        if (n-m > 1 || s == t) return false;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (m == n) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                //only alter one time
                break;
            }
        }
        return s == t || s+t[n-1] == t;
    }
};
