class Solution {
public:

    // O(n^2)
    // int wiggleMaxLength(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;
    //     if (nums.size() == 1) return 1;
        
    //     vector<int> diff;
    //     for (int i = 0; i+1 < nums.size(); i++) 
    //         diff.push_back(nums[i+1]-nums[i]);
        
    //     vector<int> dp(nums.size(), 0);
    //     for (int i = 0; i+1 < nums.size(); i++) {
    //         dp[i] = diff[i] == 0 ? 0 : 1;
    //         for (int j = i-1; j >= 0; j--) {
    //             if (diff[i]*diff[j] < 0)
    //                 dp[i] = max(dp[i], dp[j]+1);
    //         }
    //     }
        
    //     int maxv = 0;
    //     for (int i = 0; i+1 < nums.size(); i++)
    //         maxv = max(maxv, dp[i]+1);
    //     return maxv;
    // }
    
    // O(n)
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        
        vector<int> diff;
        for (int i = 0; i+1 < nums.size(); i++) 
            diff.push_back(nums[i+1]-nums[i]);
        
        int nzero = 0;
        while (nzero+1 < nums.size() && diff[nzero] == 0)
            nzero++;
        
        if (nzero+1 >= nums.size()) return 1;
        int len1 = 1, pre = diff[nzero];
        // cout << nzero << endl;
        for (int i = nzero+1; i+1 < nums.size(); i++) {
            if (pre * diff[i] < 0) {
                len1++;
                pre = diff[i];
            }
        }
        // cout << len1 << endl;
        return len1+1;
    }
};
