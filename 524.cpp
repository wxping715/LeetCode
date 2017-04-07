class Solution {
public:
    
    
    /*
    * O(n*len)
    */
    string findLongestWord(string s, vector<string>& d) {
        int maxl = 0;
        string res;
        for (string t : d) {
            if (!isSubsequence(s, t) || t.length() < maxl) continue;
            if (t.length() > maxl || t < res) {
                maxl = t.length();
                res = t; 
            }
        }
        return res;
    }
    
    bool isSubsequence(const string& s, const string& t) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[j]) {
                j++;
                if (j >= t.length()) return true;
            }
        }
        return false;
    }
};
