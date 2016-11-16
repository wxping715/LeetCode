class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    
        int flag = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long ldvd = labs(dividend);
        long long ldvo = labs(divisor);
        
        int res = 0;
        while (ldvd >= ldvo) {
            long long tdvo = ldvo;
            int offset = 1;
            while (ldvd >= (tdvo << 1)) {
                tdvo <<= 1;
                offset <<= 1;
                // cout << tdvo << " " << offset << endl;
            }
            ldvd -= tdvo;
            res += offset;
        }
        return res*flag;
    }
};
