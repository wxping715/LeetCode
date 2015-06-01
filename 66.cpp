class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[len-1] += 1;
        
        int carry = 0;
        for(int i = len-1;i >= 0;i--){
            digits[i] += carry;
            
            carry = digits[i]/10;
            digits[i] = digits[i] - carry*10;
            
            if(carry == 0) break;
        }
        if(carry > 0)
            digits.insert(digits.begin(),carry);
            
        return digits;
    }
};
