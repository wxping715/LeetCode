class Solution {
public:
    // 0-1 packet
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum&1) return false;
        
        int size = sum/2, dp[size+1];
        fill(dp, dp+size+1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int v = size; v >= nums[i]; v--)
               if (dp[v-nums[i]]) dp[v] = true;
        }
        return dp[size];
    }
};
