/*There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.*/

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        
        int same = k, diff = k*(k-1);
        for (int i = 3; i <= n; i++) {
            int temp = same;
            same = diff;
            diff = (temp + diff)*(k-1);
        }
        return same+diff;
    }
};
