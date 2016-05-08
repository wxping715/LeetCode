class Solution {
public:
    
    /*
    * same with the combination II, just limit the amount of numbers.
    */
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        dfs(candidates, n, path, -1, 0, k);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& path, int last_idx, int cnt, int k) {
        if (cnt == k && target != 0) return;
        
        for (int i = last_idx+1;i < candidates.size(); i++) {
            if (target == candidates[i] && cnt+1 == k) {
                path.push_back(candidates[i]);
                res.push_back(vector<int>(path.begin(), path.end()));
                path.pop_back();
            } else if (target > candidates[i]) {
                path.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], path, i, cnt+1, k);
                path.pop_back();
            }
        }
    }
};
