class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        
        int p = 1;
        ret[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            p *= nums[i-1];
            ret[i] = p;
        }
        
        p = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            p *= nums[i+1];
            ret[i] *= p;
        }
        return ret;
    }
};
