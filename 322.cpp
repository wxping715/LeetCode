class Solution {
public:
    /*
    * dp[n] = min(dp[n-coins[i]], dp[coins[i]) where 0 <= i <= coins.size() and coins[i] <= n
    */
    int MAX_INT = 0x3fffffff;
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1, MAX_INT);
        
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
            if (amount >= coins[i])
                dp[coins[i]] = 1;
            
        for(int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i < coins[j] || dp[i-coins[j]] == MAX_INT) continue;
                if (dp[i] > dp[coins[j]] + dp[i-coins[j]]) 
                    dp[i] = dp[coins[j]] + dp[i-coins[j]];
            }
        }
        return dp[amount] != MAX_INT ? dp[amount] : -1;
    }
};
