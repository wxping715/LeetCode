class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 2) return res;
        
        vector<bool> hash(nums.size(), false);
        vector<int> pre(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = res.size();
            hash[i] = false;
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] > nums[i]) continue;
                
                if (!hash[j]) {
                    res.push_back(vector<int>(2, nums[i]));
                    res.back()[0] = nums[j];
                }
                
                for (int k = pre[j]; k < pre[j+1]; k++) {
                    res.push_back(res[k]);
                    res.back().push_back(nums[i]);
                }
                if (nums[i] == nums[j]) {
                    hash[i] = true;
                    break;
                }
            }
        }
        return res;
    }
    
};
