class Solution {
public:

    /*
    * dfs search
    *   1. using the pruning optimization
    *   2. using the last_idx to not generate the duplicate comniantions
    */
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, path, 0);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& path, int last_idx) {
        //pruning
        if (target < candidates[0]) return;
        
        for (int i = last_idx;i < candidates.size(); i++) {
            if (target == candidates[i]) {
                path.push_back(candidates[i]);
                res.push_back(vector<int>(path.begin(), path.end()));
                path.pop_back();
            } else if (target > candidates[i]) {
                path.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], path, i);
                path.pop_back();
            }
        }
    }
};
