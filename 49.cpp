/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> anagrams;
        for (string s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            anagrams[t].insert(s);
        }
        
        vector<vector<string>> v;
        for (auto mit : anagrams) {
            vector<string> t(mit.second.begin(), mit.second.end());
            v.push_back(t);
        }
        return v;
    }
};
