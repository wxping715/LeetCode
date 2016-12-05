class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> dirs;
        int curLen = 0, maxLen = 0, level = -1, tnum = 0;
        string curdir;
        bool isfile = false;
        
        for (int i = 0; i < input.length(); i++) {
             char ch = input[i];
             if (ch == '\n') {
                 if (tnum > level) {
                     dirs.push(curdir);
                     level = tnum;
                     curLen += curdir.length();
                 } else if (tnum <= level) {
                     curLen = curLen - dirs.top().length() + curdir.length();
                     dirs.pop();
                     dirs.push(curdir);
                     level = tnum;
                 }
                 curdir = "";
                 tnum = 0;
                 isfile = false;
                 
                 cout << dirs.size() << " " << curLen << endl;
                 if (isfile) maxLen = max(maxLen, curLen);
             }
             else if (ch == '\t') tnum++;
             else if (ch == '.') isfile = true;
             else {
                 curdir.push_back(ch);
             }
        }
        
        if (isfile) {
            dirs.push(cur_dir);
            curLen += curdir.length();
            maxLen = max(curLen, maxLen);
        }
        
        return maxLen;
    }
};
