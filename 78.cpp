class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res, fres;
        vector<int> path;
        
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
        for (int i = c; i <= nums.size()-r; i++) {
            path.push_back(nums[i]);
            generate(nums, res, path, r-1, i+1);
            path.pop_back();
        }
    }
};
