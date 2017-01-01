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
