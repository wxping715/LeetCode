class Solution {
public:

    /*
    * My DP Version
    * dp[i][sum] means the number of ways to make up sum from 0 to i
    * dp[i][sum] = dp[i-1][sum-nums[i]] + dp[i-1][sum+nums[i]]
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, res = 0;
        for (int num : nums)
            sum += num;
        
        if ((S > sum) || (-S < -sum)) return 0;
        if (nums.empty()) {
            if (S == 0) return 1;
            return 0;
        }
        
        vector<int> pre(2*sum+2, 0);
        vector<int> cur(2*sum+2, 0);
        int offset = sum;
    
        pre[nums[0]+offset] += 1, pre[-nums[0]+offset] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int s = -sum; s <= sum; s++) {
                cur[s+offset] = 0;
                if (s-nums[i] >= -sum) cur[s+offset] += pre[s+offset-nums[i]];
                if (s+nums[i] <= sum) cur[s+offset] += pre[s+offset+nums[i]];
            }
            pre = cur;
        }
        
        return pre[S+offset];
    }
    
    /*
    * My Search Version
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums) sum += num;
        
        if (S > sum || -S < -sum) return 0;
        if (nums.empty()) {
            if (S == 0) return 1;
            return 0;
        }
        
        return search(nums, S, (int)nums.size()-1);
    }
    
    int search(vector<int>& nums, int S, int i) {
        if (i == 0) {
            int res = 0;
            if (S == nums[i]) res++;
            if (S == -nums[i]) res++;
            return res;
        }
        
        return search(nums, S+nums[i], i-1) + search(nums, S-nums[i], i-1);
    }
    
    /*
    * subset version from solutions
    * assume P is the positive set, N is the negative set
    * so, sum(P) - sum(N) = target
    * sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N) = target + sum(nums)
    * 2 * sum(P) = target + sum(nums)
    * So we should find how many ways can be find such a subset P where it's sum is (target + sum(nums))/2
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (S > sum || -S < -sum) return 0;
        if (nums.empty()) {
            if (S == 0) return 1;
            return 0;
        }
        if ((sum+S)&1) return 0;
        return subset(nums, (sum+S)/2);
    }
    
    int subset(vector<int>& nums, int s) {
        vector<int> dp(s+1, 0);
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i-n];
        return dp[s];
    }
};
