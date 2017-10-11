/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        deque<int> dq;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.emplace(i);
            else if (s[i] == '*') dq.push_back(i);
            else {
                if (!st.empty()) st.pop();
                // no * match with )
                else if (dq.empty()) return false;
                else dq.pop_front();
            }
        }
        
        // more ( than *
        if (dq.size() < st.size()) return false;
        while (!st.empty()) {
            // * (
            if (st.top() > dq.back()) return false;
            else {
                st.pop();
                dq.pop_back();
            }
        }
        return true;
    }
};
