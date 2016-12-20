class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        for (int i = 1; i <= num.size()/2; i++)
            for (int j = 1; j <= (num.size()-1)/2; j++) {
                if (check(num.substr(0,i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        return false;
    }
    
    bool check(string num1, string num2, string num) {
        if ((num1.size()>1 && num1[0]=='0') || (num2.size()>1 && num2[0]=='0')) return false;
        string sum = add(num1, num2);
        if (sum == num) return true;
        if (num.size()<sum.size() || num.substr(0, sum.size()) != sum) return false;
        return check(num2, sum, num.substr(sum.size()));
    }
    
    string add(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int carry = 0, i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            int val = a[i++]-'0'+b[j++]-'0'+carry;
            carry = val/10;
            res.push_back(val%10+'0');
        }
        while (i < a.length()) {
            res.push_back((a[i]-'0'+carry)%10+'0');
            carry = (a[i++]-'0'+carry)/10;
        }
        while (j < b.length()) {
            res.push_back((b[j]-'0'+carry)%10+'0');
            carry = (b[j++]-'0'+carry)/10;
        }
        if (carry != 0) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
