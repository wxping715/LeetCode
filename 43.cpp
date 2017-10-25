/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> median(num1.size()+num2.size()-1, 0);
        string prod;
        if (num1.empty() || num2.empty()) return prod;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int offset = 0;
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) 
                median[offset+j] += (num2[j]-'0')*(num1[i]-'0');
            offset++; 
        }
        
        int carry = 0;
        for (int i = 0; i < median.size(); i++) {
            int newv = median[i]+carry;
            carry = newv/10;
            median[i] = newv%10;
        }
        
        while (carry) {
            median.push_back(carry%10);
            carry /= 10;
        }
        
        int idx = median.size()-1;
        while (idx > 0 && median[idx] == 0)
            idx--;
        
        for (int i = idx; i >= 0; i--)
            prod.push_back(median[i]+'0');
        return prod;
    }
};
