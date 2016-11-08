class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.emplace(start, 0);
        visited.insert(start);
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == end) return p.second;
            
            for (auto it = bank.begin(); it != bank.end(); it++) {
                if (diff(*it, p.first) == 1 && visited.find(*it) == visited.end()) {
                    q.emplace(*it, p.second+1);
                    visited.insert(*it);
                }
            }
        }
        return -1;
    }
    
    int diff(string s1, string s2) {
        int res = 0;
        for (int i = 0; i < 8; i++)
            if (s1[i] != s2[i]) res++;
        return res;
    }
};
