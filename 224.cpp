class Solution {
public:
    int calculate(string s) {
        stack<char> oprs;
        stack<int> opds;
        int num = 0, rst = 0, sign = 1;
        for (char ch : s) {
            if (isdigit(ch)) num = num*10+ch-'0';
            else {
                rst += sign * num;
                num = 0;
                if (ch == '+') sign = 1;
                else if (ch == '-') sign = -1;
                else if (ch == '(') {
                    opds.push(rst);
                    oprs.push(sign);
                    rst = 0;
                    sign = 1;
                } else if (ch == ')') {
                    rst = opds.top() + oprs.top()*rst;
                    opds.pop();
                    oprs.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }

};
