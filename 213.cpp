class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        return max(orob(nums, 0, nums.size()-2), orob(nums, 1, nums.size()-1));
    }
    
    int orob(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
