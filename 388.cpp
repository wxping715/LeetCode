class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> dirs;
        int curLen = 0, maxLen = 0, level = -1, tnum = 0;
        string curdir;
        bool isfile = false;
        
        for (int i = 0; i < input.length(); i++) {
            while (i < input.length() && input[i] != '\n') {
                char ch = input[i++];
                if (ch != '\t') {
                    curdir.push_back(ch);
                    if (ch == '.') isfile = true;
                } else tnum++;
            }
            
            if (tnum > level) {
                 dirs.push(curdir);
                 level = tnum;
                 curLen += curdir.length();
             } else {
                 while (level >= tnum) {
                     curLen = curLen - dirs.top().length();
                     dirs.pop();
                     level--;
                 }
                 curLen += curdir.length();
                 dirs.push(curdir);
                 level = tnum;
             }
             if (isfile) maxLen = max(maxLen, curLen+(int)dirs.size()-1);
             
             curdir = "";
             tnum = 0;
             isfile = false;
        }
        return maxLen;
    }
};
