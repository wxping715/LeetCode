class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            // cout << s.size() << endl;
            if (!isOperator(token)) {
                s.push(stoi(token));
                continue;
            }
            
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            if (token == "+") s.push(op1+op2);
            else if (token == "-") s.push(op1-op2);
            else if (token == "*") s.push(op1*op2);
            else s.push(op1/op2);
        }
        return s.top();
    }
    
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
};
