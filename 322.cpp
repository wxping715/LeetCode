/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    /*
    * dp[n] = min(dp[n-coins[i]], dp[coins[i]) where 0 <= i <= coins.size() and coins[i] <= n
    */
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1, amount+1);
        sort(coins.begin(), coins.end());
        
        dp[0] = 0;
        int k = 0;
        for (int i = 1; i <= amount; i++) {
            if (k < coins.size() && coins[k] == i) {
                dp[i] = 1;
                k++;
            }
            else {
                for (int j = 0; j < k; j++) {
                    if (dp[i-coins[j]] > amount) continue;
                    else dp[i] = min(dp[i-coins[j]]+1, dp[i]);
                }
            }
        }
        return (dp[amount] > amount ? -1 : dp[amount]);
    }
};
