class Solution {
public:
    /*
    * dfs search
    *   1. the difference to the previous problem is using each element only once
    *   2. if (i > last_idx+1 && candidates[i]==candidates[i-1]) continue is importent
    */
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, path, -1);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& path, int last_idx) {
        for (int i = last_idx+1;i < candidates.size(); i++) {
            if (i > last_idx+1 && candidates[i]==candidates[i-1]) continue;
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
