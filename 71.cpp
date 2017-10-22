/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        stack<string> st;
        path.push_back('/');
        for (char ch : path) {
            if (ch == '/') {
                if (cur == "") ;
                else if (cur == ".") ;
                else if (cur == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else st.push(cur);
                cur = "";
            }
            else cur.push_back(ch);
        }
        
        if (st.empty()) return "/";
        string res = "";
        while (!st.empty()) {
            res = "/"+st.top()+res;
            st.pop();
        }
        return res;
    }
};
