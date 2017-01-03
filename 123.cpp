class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        vector<int> t1(prices.size()), t2(prices.size());
        
        int minp = INT_MAX, maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            maxprofit = max(maxprofit, prices[i]-minp);
            t1[i] = maxprofit;
            minp = min(prices[i], minp);
        }
        
        int maxp = 0;
        maxprofit = 0;
        for (int i = prices.size()-1; i >= 0; i--) {
            maxprofit = max(maxp-prices[i], maxprofit);
            t2[i] = maxprofit;
            maxp = max(maxp, prices[i]);
        }
        
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
            profit = max(profit, t1[i]+t2[i]);
        return profit;
    }
};
