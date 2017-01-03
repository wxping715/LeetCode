class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size()/2) return maxProfitSimple(prices);
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i++) {
            int localMax = -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                dp[i][j] = max(dp[i][j-1], prices[j]+localMax);
                localMax = max(localMax, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][prices.size()-1];
    }
    
    int maxProfitSimple(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i]>prices[i-1])
                profit += prices[i] - prices[i-1];
        return profit;
    }
};
