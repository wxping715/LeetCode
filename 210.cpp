class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        // inversed graph
        vector<vector<int>> graph(numCourses, vector<int>());
        
        for (vector<pair<int,int>>::iterator it = prerequisites.begin(); it != prerequisites.end(); it++) {
            graph[it->second].push_back(it->first);
            degree[it->first] += 1;
        }
        
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            bool found = false;
            int j;
            for (j = 0; j < numCourses; j++){
                if (degree[j] == 0) {
                    found = true;
                    break;
                }
            }
            
            if (!found) return vector<int>();
            res.push_back(j);
            for (int k = 0; k < graph[j].size(); k++)
                degree[graph[j][k]]--;
            degree[j] = 0x3f3f3f3f;
        }
        return res;
    }   
};
