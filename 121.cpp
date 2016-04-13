class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_price = -0x3fffffff, max_profit = 0;
        for (int i = prices.size()-1;i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            max_profit = max(max_profit, max_price - prices[i]);
        }
        return max_profit;
    }
};
