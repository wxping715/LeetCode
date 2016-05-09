class Solution {
public:
    /*
    * 1. the general method is to divide 3 continuly.
    * 2. the param is integer, so the maximul which is power of three is 3^19=1162261467, if num is power of three, then 3^19 % num == 0;
    */
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        const int m = 1162261467;
        return m % n == 0;
    }
};
