/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    /*
    * using the binary search way to determine
    * NOTE: must promise the right value smaller than 65536
    */
    bool isPerfectSquare(int num) {
        const int UPBOUND = 65536;
        int left = 0, right = min(num, UPBOUND), mid;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (mid*mid == num) return true;
            else if (mid*mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
