class Solution {
public:
    // 谜之题目
    typedef unordered_map<string, multiset<string>> Graph;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        Graph graph;
        for (auto ticket : tickets)
            graph[ticket.first].insert(ticket.second);
            
        vector<string> path;
        dfs(graph, "JFK", path);
        return vector<string>(path.rbegin(), path.rend());
    }
    
    void dfs(Graph& graph, string src, vector<string>& path) {
        while (graph[src].size()) {
            string dst = *graph[src].begin();
            graph[src].erase(graph[src].begin());
            dfs(graph, dst, path);
        }
        path.push_back(src);
    }
};
