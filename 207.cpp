class Solution {
public:
    /*
    * determine whether the DAG has cycle, dfs
    */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        
        for (int i = 0; i < numCourses; i++) {
            visited[i] = true;
            if (!dfs(i, graph, visited)) return false;
            visited[i] = false;
        }
        return true;
    }
    
    bool dfs(int v, vector<vector<int>>& graph, vector<bool> &visited) {
        for (int i = 0; i < graph[v].size(); i++) {
            int cur = graph[v][i];
            if (visited[cur]) return false;
            
            visited[cur] = true;
            if (!dfs(cur, graph, visited)) return false;
            visited[cur] = false;
        }
        return true;
    }
};
