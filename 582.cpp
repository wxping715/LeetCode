class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < ppid.size(); i++)
            children[ppid[i]].push_back(pid[i]);
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            auto cur = q.front();
            res.push_back(cur);
            q.pop();
            
            if (!children.count(cur)) continue;
            for (int c : children[cur])
                q.push(c);
        }
        return res;
    }   
};
