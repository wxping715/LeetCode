class Solution {
public:

    /**
     * stack version 
     */
    // string decodeString(string s) {
    //     stack<int> num;
    //     stack<string> str;
        
    //     int number = 0;
    //     string cur_str = "";
    //     for (char ch : s) {
    //         if (isdigit(ch)) {
    //             number = number * 10 + (ch-'0');
    //         } else if (ch == '[') {
    //             num.push(number);
    //             str.push(cur_str);
    //             number = 0;
    //             cur_str = "";
    //         } else if (ch == ']') {
    //             int k = num.top(); num.pop();
    //             string nstr = str.top(); str.pop();
    //             while (k--) nstr += cur_str;
                
    //             cur_str = nstr;
    //         } else {
    //             cur_str.push_back(ch);
    //         }
    //     }
    //     return cur_str;
    // }
    
    
    /**
     * dfs version
     */
    string decodeString(string s) {
       int idx = 0;
       return decode(s, idx);
    }
    
    string decode(string s, int& idx) {
        string cur_str;
        while (idx < s.length() && s[idx] != ']') {
            if (!isdigit(s[idx])) cur_str.push_back(s[idx++]);
            else {
                int num = 0;
                while (idx < s.length() && isdigit(s[idx])) 
                    num = num*10 + s[idx++]-'0';
                
                //skip [
                idx++;
                string t = decode(s, idx);
                //skip ]
                idx++;
                while (num--) cur_str += t;
            }
        }
        return cur_str;
    }
    
};
