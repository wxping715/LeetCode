class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int> > que(people.size(), pair<int, int>(0x3f3f3f3f, 0x3f3f3f3f));
        
        for (int i = 0; i < people.size(); i++) {
            int cnt = people[i].second, idx = 0;
            while (idx < que.size() && (cnt || que[idx].first != 0x3f3f3f3f)) {
                if (que[idx].first == 0x3f3f3f3f ) cnt--;
                idx++;
            }
            que[idx].first = people[i].first;
            que[idx].second = people[i].second;
        }
        return que;
    }
    
    static bool cmp(pair<int, int>& p1, pair<int, int> &p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    }
};
