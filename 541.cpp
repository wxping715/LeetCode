class Solution {
public:
    string reverseStr(string s, int k) {
        k = min(k, (int)s.length());
        int i = 0,j;
        while (i < s.length()) {
            j = min(i+k-1, (int)s.length()-1);
            myReverse(s, i, j);
            i += 2*k;
        }
        return s;
    }
    
    void myReverse(string& s, int i, int j) {
        while (i <= j) swap(s[i++], s[j--]);
    }
};
