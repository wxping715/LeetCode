class Solution {
public:
    int calculate(string s) {
        stack<char> oprs;
        stack<int> opds;
        
        int priority[256];
        priority['+'] = 0;
        priority['-'] = 0;
        priority['*'] = 1;
        priority['/'] = 1;
        
        int num = 0;
        for (char ch : s) {
            if (isopr(ch)) {
                opds.push(num);
                num = 0;
                
                if (oprs.empty() || priority[ch] > priority[oprs.top()]) 
                    oprs.push(ch);
                else {
                    while (!oprs.empty() && priority[ch] <= priority[oprs.top()])
                        compute(opds, oprs);
                    oprs.push(ch);
                }
            } else if (ch == ' ') {
                continue;
            } else  {
                num = num*10 + ch-'0';
            }
        }
        opds.push(num);
            
        while (!oprs.empty()) {
            compute(opds, oprs);
        }
        
        return opds.top();
    }
    
    bool isopr(char ch) {
        return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
    }
    
    void compute(stack<int>& opds, stack<char>& oprs) {
        int op2 = opds.top(); opds.pop();
        int op1 = opds.top(); opds.pop();
        char opr = oprs.top(); oprs.pop();
        if (opr == '+') opds.push(op1+op2);
        else if (opr == '-') opds.push(op1-op2);
        else if (opr == '*') opds.push(op1*op2);
        else if (opr == '/') opds.push(op1/op2);
    }
};
