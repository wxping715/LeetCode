class Solution {
public:
    /*
    * dp(i, 0) means the maximum product of intervel ending with nums[i].
    * dp(i, 1) means the minimul product of intervel ending with nums[i].
    * dp(i, 0) = max(dp(i-1,1)*nums[i], dp(i-1,0)*nums[i], nums[i])
    * dp(i, 1) = min(dp(i-1,1)*nums[i], dp(i-1,0)*nums[i], nums[i])
    */
    int maxProduct(vector<int>& nums) {
        vector<int> dp0 = vecator<int>(nums.size(), -0x3f3f3f3f);
        vector<int> dp1 = vector<int>(nums.size(), 0x3f3f3f3f);
        
        dp0[0] = nums[0]; dp1[0] = nums[0];
        for (int i = 1;i < nums.size(); i++) {
            dp0[i] = max(dp0[i-1]*nums[i], dp1[i-1]*nums[i]);
            dp1[i] = min(dp0[i-1]*nums[i], dp1[i-1]*nums[i]);
            
            if (dp0[i] < nums[i]) dp0[i] = nums[i];
            if (dp1[i] > nums[i]) dp1[i] = nums[i];
        }
        
        int res = -0x3f3f3f3f;
        for (int i = 0;i < nums.size(); i++)
            if (res < dp0[i]) res = dp0[i];
        return res;
    }
};
