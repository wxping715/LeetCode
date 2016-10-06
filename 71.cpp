class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string str;
        if (path.empty()) return "";
        
        // append '/' to the end of string 
        path.push_back('/');
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (str == "..") {
                    if (!s.empty()) s.pop();
                }
                else if (str == ".");
                else if (str.length() > 0) s.push(str);
                str = "";
            } else 
                str.push_back(path[i]);
        }
        
        string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        if (res.length() == 0) return "/";
        
        return res;
    }
};
