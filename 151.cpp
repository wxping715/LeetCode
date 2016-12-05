class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
    
        int k = 0, l = 0;
        bool word = false;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            if (!word && s[i] == ' ') continue;
            if (s[i] == ' ') {
                reverseRange(s, l, i-1, k);
                word = false;
            } else if (!word) {
                l = i;
                word = true;
            }
        }
        if (word && l < s.length()) reverseRange(s, l, s.length()-1, k);
        // cout << k << endl;
        if (k == 0) s.erase(0, s.length());
        else s.erase(k-1, s.length()-k+1);
    }
    
    void reverseRange(string &s, int l, int r, int& k) {
        int pk = k;
        for (int i = l; i <= r; i++)
            s[k++] = s[i];
        reverse(s.begin()+pk, s.begin()+k);
        s[k++] = ' ';
    }
};
