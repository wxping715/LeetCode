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
