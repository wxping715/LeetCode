class Solution {
public:
    string solveEquation(string equation) {
        // ax + b = 0
        int a = 0, b = 0, flag = 1, num = 0, cflag = 1;
        
        int i = 0;
        while (i < equation.length()) {
            while (i < equation.length() && equation[i] >= '0' && equation[i] <= '9') {
                num = num * 10 + equation[i] - '0';
                i++;
            }
            num *= cflag;
            
            if (i >= equation.size()) b += -flag*num;
            else if (equation[i] == 'x') {
                // +x or x or =x
                if (i == 0 || equation[i-1] == '+' || equation[i-1] == '=') a += flag;
                // -x
                else if (equation[i-1] == '-') a += -flag;
                // 2x
                else a += flag*num;
            }
            else {
                b += -flag*num;
                if (equation[i] == '+') cflag = 1;
                else if (equation[i] == '-') cflag = -1;
                else {
                    // 5+x=7, should set cflag as 1
                    cflag = 1;
                    flag = -1;
                }
            }
            num = 0;
            i++;
        }
        
        cout << a <<  " " << b << endl;
        
        if (a == 0 && b != 0) return "No solution";
        else if (a == 0) return "Infinite solutions";
        else return "x="+to_string(b/a);
    }
};

// "x+5-3+x=6+x-2"
// "2x+5-3-x=6"
// "5=3"
// "0=0"
// "5+x=7"
// "x=x"
