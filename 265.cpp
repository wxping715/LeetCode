/*There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (!n) return 0;
        int k = costs[0].size();
        if (!k) return 0;
        
        vector<int> cost(k, 0);
        for (int i = 0; i < n; i++) {
            int minxi = -1, minxj = -1;
            for (int j = 0; j < k; j++) {
                if (minxi == -1 || cost[j] <= cost[minxi]) {
                    minxj = minxi;
                    minxi = j;
                } else if (minxj == -1 || cost[j] <= cost[minxj]) {
                    minxj = j;
                }
            }
            
            // cout << minxi << " " << minxj << endl;
            minxj = minxj == -1 ? minxi : minxj;
            int smin = cost[minxj];
            for (int j = 0; j < k; j++) {
                if (j != minxi) cost[j] = cost[minxi] + costs[i][j];
            }
            cost[minxi] = smin + costs[i][minxi];
        }
        
        int res = INT_MAX;
        for (int c : cost)
            res = min(c, res);
        return res;
    }
};
