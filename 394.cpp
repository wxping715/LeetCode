/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:

    /**
     * stack version 
     */
    string decodeString(string s) {
        stack<pair<int, string>> st;
        
        string cur = "", num = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '[') {
                st.push({stoi(num), cur});
                num = ""; cur = "";
            }
            else if (ch == ']') {
                auto top = st.top();
                st.pop();
                cur = top.second + copyString(cur, top.first);
            }
            else if (ch >= '0' && ch <= '9')
                num.push_back(ch);
            else 
                cur.push_back(ch);
        }
        return cur;
    }
    
    string copyString(string s, int t) {
        string res = "";
        while (t--)
            res += s;
        return res;
    }
    
    
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
