/*Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashmap;
        for (string s : strings) {
            string ns = convert(s);
            hashmap[ns].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto it : hashmap)
            res.push_back(it.second);
        return res;
    }
    
    string convert(string str) {
        string nstr = "";
        int diff = str[0] - 'a';
        for (char ch : str)
            nstr.push_back(ch-diff < 'a' ? ch+26-diff : ch-diff);
        return nstr;
    }
};
