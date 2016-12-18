class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res, fres;
        vector<int> path;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            generate(nums, res, path, i, 0);
            fres.insert(fres.end(), res.begin(), res.end());
            res.clear();
        }
        return fres;
    }
    
    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int r, int c) {
        if (r == 0) {
            res.push_back(vector<int>(path.begin(), path.end()));
            return;
        }
        
        int pre = INT_MAX;
        for (int i = c; i <= nums.size()-r; i++) {
            if (nums[i] == pre) continue;
            
            path.push_back(nums[i]);
            generate(nums, res, path, r-1, i+1);
            path.pop_back();
            pre = nums[i];
        }
    }
};
