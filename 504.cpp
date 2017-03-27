class Solution {
public:
    string convertToBase7(int num) {
        int flag = num >= 0 ? 1 : -1;
        num = num > 0 ? num : -num;
        string res = "";
        while (num) {
            res.push_back((num%7)+'0');
            num /= 7;
        }
        
        if (flag == -1) res.push_back('-');
        if (res.empty()) res.push_back('0');
        reverse(res.begin(), res.end());
        return res;
    }
};
