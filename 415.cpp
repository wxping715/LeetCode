class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string res;
        int idx = 0, carry = 0;
        while (idx < num1.length() || idx < num2.length()) {
            int ch1, ch2;
            ch1 = idx < num1.length() ? num1[idx]-'0' : 0;
            ch2 = idx < num2.length() ? num2[idx]-'0' : 0;
            
            res.push_back((carry+ch1+ch2)%10+'0');
            carry = (carry+ch1+ch2)/10;
            idx++;
        }
        if (carry != 0)
            res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};
