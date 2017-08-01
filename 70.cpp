/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1;
        for (int i = 2; i <= n; i++) {
            int t = cur;
            cur = cur + pre;
            pre = t;
        }
        return cur;
    }
};
