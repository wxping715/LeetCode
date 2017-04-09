class Solution {
public:
    string reverseWords(string s) {
        int si = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' || i+1 == s.length()) {
                if (si != -1) {
                    reverse(s, si, (s[i] == ' ' ? i-1 : i));
                    si = -1;
                }
            }
            else if (si == -1) si = i;
        }
        return s;
    }
    
    void reverse(string& s, int si, int ei) {
        int i = si, j = ei;
        while (i <= j) swap(s[i++], s[j--]);
    }
};
