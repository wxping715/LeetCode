/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs.front();
        
        int s = 0;
        while (true) {
            char ch = 0;
            bool end = false;
            for (string str : strs) {
                if (s >= str.length() || (ch != 0 && str[s] != ch)) {
                    end = true;
                    break;
                }
                ch = str[s];
            }
            if (end) break;
            s++;
        }
        return strs.front().substr(0, s);
    }
};
