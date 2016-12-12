class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            int l = i;
            while (i < s.length() && s[i] != ' ') i++;
            reverse(s.begin()+l, s.begin()+i);
        }
    }
};
