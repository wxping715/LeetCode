class Solution {
public:

    /*
    * O(N^2)
    */
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> hashmap;
        for (string str : strs) 
            hashmap[str]++;
        
        int maxl = -1;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            if (it->second > 1) continue;
            bool found = true;
            for (auto it2 = hashmap.begin(); it2 != hashmap.end(); it2++) {
                if (it->first == it2->first) continue;
                if (isSubSequence(it2->first, it->first)) {
                    found = false;
                    break;
                }
            }
            if (found) maxl = max(maxl, (int)it->first.length());
        }
        return maxl;
    }
    
    bool isSubSequence(const string& s, const string& t) {
        if (t.length() > s.length()) return false;
        if (s == t) return true;
        
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
