/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.*/

class Solution {
public:

    typedef vector<vector<int>> Graph;
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        Graph graph(n, vector<int>());
        for (auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                bfs(graph, i, visited);
            }
        }
        return res;
    }
    
    void bfs(Graph &graph, int u, vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int v : graph[cur]) 
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
        }
    }
};
