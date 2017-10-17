/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/

class Solution {
public:
    
    bool judgeSquareSum(int c) { 
        int l = 0, r = (int)sqrt(c);
        while (l <= r) {
            int v = l*l + r*r;
            if (v < c) l += 1;
            else if (v > c) r -= 1;
            else return true;
        }
        return false;
    }
};
