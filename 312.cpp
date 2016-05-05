class Solution {
public:
    /*
    * dp(i,j) means the maximul coins we can get from location i to location j
    * dp(i,j) = max(dp(i,k-1) + dp(k+1,j) + nums[i-1]*nums[k]*nums[j+1]) where k is the LAST bulloon to burst in intervel between i and j.
    * 
    * tips:
    *      for the purpose easy to process nums product, we add two 1s at the head and tail of the arrays
    */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        for (int len = 1; len <= n; len++)
            for (int i = 1; i <= n-len+1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
                // cout << i << " " << j << " "<< dp[i][j] << endl;
            }
        
        return dp[1][n];
    }
};
