class Solution {
public:
    //using string directly method
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> once, twice;
        vector<string> res;

        if (s.length() < 10) return res;
        string cur = s.substr(0, 10);
        int idx = 9;
        do {
            if (once.find(cur) == once.end())
                once.insert(cur);
            else
                twice.insert(cur);
            
            cur.erase(cur.begin());
            cur.push_back(s[++idx]);
        } while (idx < s.length());
        
        res = vector<string>(twice.begin(), twice.end());
        return res;
    }
};
