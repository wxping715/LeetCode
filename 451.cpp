class Solution {
public:
    string frequencySort(string s) {
        int hash[256] = {0};
        for (char ch : s) hash[ch]++;
        
        vector<pair<int, int>> v;
        for (int i = 0; i < 256; i++) {
            if (hash[i] != 0)
                v.emplace_back(i, hash[i]);
        }
        sort(v.begin(), v.end(), compare);
        
        string res = "";
        for (auto p : v) {
            while (p.second--)
                res.push_back(p.first);
        }
        return res;
    }
    
    bool static compare(const pair<int, int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};
