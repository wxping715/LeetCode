class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string res = "";
        int size = 2*numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += size) {
                res.push_back(s[j]);
                if (i != 0 && i != numRows-1) {
                    int t = j+size-2*i;
                    if (t < s.length())
                        res.push_back(s[t]);
                }
            }
        }
        return res;
    }
};
