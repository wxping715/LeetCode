class Solution {
public:
    /*
    * dp[i] means the numbers of 1 bit in i-th integers
    * dp[i] = dp[i-2^j]+1 where 2^j < i
    *       = 1 where 2^j = i
    */
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        
        int cure = 1;
        dp[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (2*cure == i) {
                dp[i] = 1;
                cure *= 2;
            }
            else dp[i] = dp[i-cure] + 1;
        }
        return dp;
    }
};
