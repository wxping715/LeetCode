/*For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?
Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.*/

class Solution {
public:
    typedef vector<vector<int>> Graph;
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        Graph graph(n, vector<int>());
        for (auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
     
        vector<int> path;
        bfs(graph, 0, path);
        
        int s = path[0];
        path.clear();
        bfs(graph, s, path);
        vector<int> res;
        if (path.size()%2 == 0) res.push_back(path[path.size()/2-1]);
        res.push_back(path[path.size()/2]);
        
        return res;
    }
    
    void bfs(Graph graph, int u, vector<int>& path) {
        vector<int> parent(graph.size());
        parent[u] = -1;
        queue<int> q;
        
        vector<int> visited(graph.size(), 0);
        q.push(u);
        visited[u] = 1;
        int cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int v : graph[cur]) {
                if (visited[v]) continue;
                parent[v] = cur;
                q.push(v);
                visited[v] = 1;
            }
        }
        
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
    }  
};
