class Solution {
public:
    /*
    * the condition return true:
    *   1. number of elements is same
    *   2. the map relation is same
    */
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> relation;
        unordered_map<string, char> rrelation;
        unordered_map<char, string>::iterator it;
        unordered_map<string, char>::iterator rit;
        
        vector<string> items = split(str, ' ');
        if (items.size() != pattern.length()) return false;
        
        for (int i = 0;i < pattern.length(); i++) {
            it = relation.find(pattern[i]);
            rit = rrelation.find(items[i]);
            
            if ( (it == relation.end() && rit != rrelation.end()) ||
                 (it != relation.end() && rit == rrelation.end()))
                 return false;
            if (it == relation.end()) {
                relation[pattern[i]] = items[i];
                rrelation[items[i]] = pattern[i];
            }
            else if (it->second != items[i] || rit->second != pattern[i]) return false;
        }
        return true;
    }
    
    vector<string> split(string str, char ch) {
        vector<string> res;
        int pidx = 0, i;
        for (i = 0;i < str.length(); i++) {
            if (str[i] != ch) continue;
            
            res.push_back(str.substr(pidx, i-pidx));
            pidx = i+1;
        }
        res.push_back(str.substr(pidx, i-pidx));
        return res;
    }
};
