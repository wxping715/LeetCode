class Solution {
public:

    // dfs version
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        
        int groups = 0;
        vector<bool> visited(M.size(), false);
        for (int u = 0; u < M.size(); u++)
            if (!visited[u]) {
                groups++;
                dfs(visited, M, u);
            }
        return groups;
    }
    
    void dfs(vector<bool>& visited, vector<vector<int>>& M, int u) {
        if (visited[u]) return;
        visited[u] = true;
        
        for (int v = 0; v < M.size(); v++) {
            if (v == u || M[u][v] != 1) continue;
            dfs(visited, M, v);
        }
    }
};
