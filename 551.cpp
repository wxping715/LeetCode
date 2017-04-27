class Solution {
public:
    bool checkRecord(string s) {
        char pch = ' ', fch = ' ';
        bool absent = false;
        for (char ch : s) {
            if (ch == 'A') {
                if (absent) return false;
                absent = true;
            } else if (ch == 'L') {
                if (fch == 'L' && pch == 'L') return false;
            }
            fch = pch;
            pch = ch;
        }
        return true;
    }
};
