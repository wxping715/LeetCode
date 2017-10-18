/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        
        int flag = x > 0 ? 1 : -1;
        long k = x * (long)flag;
        
        long res = 0;
        while (k) {
            res = res*10 + k%10;
            k /= 10;
        }
        
        if (res > INT_MAX) return 0;
        return flag * res;
    }
};
