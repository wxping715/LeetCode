class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b;
        int carry = a&b;
        while (carry) {
            int pcarry = carry;
            carry = (pcarry << 1) & sum;
            sum = (pcarry << 1) ^ sum;
        }
        return sum;
    }
};
