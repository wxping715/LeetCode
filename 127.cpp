class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        queue<pair<string,int>> q;
        q.push(make_pair(start,1));
        while(!q.empty()) {
            string s = q.front().first;
            int len = q.front().second;
            if(s==end) return len;
            q.pop();
            vector<string> neighbors = findNeighbors(s, dict);
            for(int i=0; i<neighbors.size(); i++) 
                q.push(make_pair(neighbors[i],len+1));
        }
        return 0;
    }
    
    vector<string> findNeighbors(string s, unordered_set<string> &dict) {
        vector<string> ret;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            for(int j=0; j<26; j++) {
                if(c=='a'+j) continue;
                s[i] = 'a'+j;
                if(dict.count(s)) {
                    ret.push_back(s);    
                    dict.erase(s);    
                }
            }
            s[i] = c;
        }
        return ret;
    }
};
