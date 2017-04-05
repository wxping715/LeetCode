class Solution {
public:

    /*
    * MY SOLUTION
    * dp[i][j] means the maximum value we can get from i to j
    * 1. 若取nums[i], 那么对手就能取nums[i+1]或nums[j]
    *    1.1 若对手取nums[i+1], 我们能取得的最大值为dp[i+2][j]
    *    1.2 若对手取nums[j], 我们能取得的最大值为dp[i+1, j-1]
    *    对手势必让我们取得的值最小，因此dp[i][j] = nums[i] + min(dp[i+2][j], dp[i+1][j-1])
    * 2. 若取nums[j], 那么对手就能取nums[i]或nums[j-1]
    *    1.1 若对手取nums[i], 我们能取得的最大值为dp[i+1][j-1]
    *    1.2 若对手取nums[j-1], 我们能取得的最大值为dp[i, j-2]
    *    对手势必让我们取得的值最小，因此dp[i][j] = nums[j] + min(dp[i+1][j-1], dp[i][j-2])
    *
    *  3. 我们最终得的最大值为两种情况的最大值。
    */
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        
        int n = nums.size(), sum = 0;
        for (int num : nums)
            sum += num;
            
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 0; i+1 < n; i++) dp[i][i+1] = max(nums[i], nums[i+1]);
        
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i+l <= n; i++) {
                int j = i+l-1;
                dp[i][j] = nums[i] + min(dp[i+2][j], dp[i+1][j-1]);
                dp[i][j] = max(dp[i][j], nums[j]+min(dp[i+1][j-1], dp[i][j-2]));
            }
        }
        
        return dp[0][nums.size()-1]*2 >= sum;
    }
    
    /*
    * optimize space for my solution
    */
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        
        int n = nums.size(), sum = 0;
        for (int num : nums)
            sum += num;
            
        vector<int> dp1(n,0), dp2(n,0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j == i) dp2[j] = nums[j];
                else if (j == i+1) dp2[j] = max(nums[j-1], nums[j]);
                else {
                    dp2[j] = nums[i] + min(dp2[j], dp1[j-1]);
                    dp2[j] = max(dp2[j], nums[j]+min(dp1[j-1], dp2[j-2]));   
                }
            }
            
            auto tmp = dp1;
            dp1 = dp2;
            dp2 = tmp;
        }
        return dp1[n-1]*2 >= sum;
    }
    
    /*
    * OTHER'S SOLUTION
    * dp[i][j] means how much more scores player1 can get than player2
    * dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
    */
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i+l <= n; i++) {
                int j = i+l-1;
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
    
    /*
    * optimize space for other's solution
    * dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
    * so we can calculate dp from tail to head
    */
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[j] = nums[j];
                else dp[j] = max(nums[i]-dp[j], nums[j]-dp[j-1]);
            }
        }
        return dp[n-1] >= 0;
    }
};
