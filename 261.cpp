/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
    According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.*/


class Solution {
public:
    
    /*
    * dfs
    */
    // bool validTree(int n, vector<pair<int, int>>& edges) {
    //     vector<vector<int>> graph(n, vector<int>());
    //     for (auto edge : edges) {
    //         graph[edge.first].push_back(edge.second);
    //         graph[edge.second].push_back(edge.first);
    //     }
        
    //     vector<bool> visited(n, false);
    //     bool res = dfs(graph, 0, -1, visited);
    //     if (!res) return false;
        
    //     for (int i = 0; i < n; i++)
    //         if (!visited[i]) return false;
    //     return true;
    // }
    
    // bool dfs(vector<vector<int>>& graph, int u, int pre, vector<bool>& visited) {
    //     if (visited[u]) return false;
    //     visited[u] = true;
    //     for (auto v : graph[u]) {
    //         if (pre == v) continue;
    //         if (visited[v]) return false;
    //         bool res = dfs(graph, v, u, visited);
    //         if (!res) return false;
    //     }
    //     return true;
    // }
    
    // union-find
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nums(n, -1);
        for (auto edge : edges) {
            int x = find(nums, edge.first);
            int y = find(nums, edge.second);
            
            if (x == y) return false;
            nums[x] = y;
        }
        // repeated results have been remove, so need to check whether it has enough edges
        return edges.size() == n-1;
    }
    
    int find(vector<int> nums, int x) {
        if (nums[x] == -1) return x;
        int y = find(nums, nums[x]);
        nums[x] = y;
        return y;
    }
};
