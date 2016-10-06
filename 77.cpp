class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        if (n <= 0 || k < 0 || k > n) return res;
        
        generate_comb(n, k, 0, path, res);
        return res;
    }
    
    void generate_comb(int n, int r, int id, vector<int>& path, vector<vector<int>>& res) {
        if (r == 0) {
            res.push_back(vector<int>(path.begin(), path.end()));
            return;
        }
        if (r + id > n) return;
        
        for (int i = id; i+r <= n; i++) {
            path.push_back(i+1);
            generate_comb(n, r-1, i+1, path, res);
            path.pop_back();
        }
    }
};
