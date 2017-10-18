/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    
    // dfs
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, {}, result, 0);
        return result;
    }
    
    void dfs(vector<int>& nums, vector<int> subset, vector<vector<int>>& subsets, int idx) {
        if (idx == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        
        vector<int> left_subset(subset.begin(), subset.end());
        dfs(nums, left_subset, subsets, idx+1);
        subset.push_back(nums[idx]);
        dfs(nums, subset, subsets, idx+1);
    }
    
    // iteration + bit
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int size = 1 << nums.size();
        for (int i = 0; i < size; i++) {
            int k = i;
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++) {
                if (k&1) subset.push_back(nums[j]);
                k >>= 1;
            }
            result.push_back(subset);
        }
        return result;
    }
};
