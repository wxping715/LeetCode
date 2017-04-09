class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hashmap;
        int sum = 0;
        for (auto row : wall) {
            sum = 0;
            for (int i = 0; i+1 < row.size(); i++) {
                sum += row[i];
                hashmap[sum]++;
            }
        }
        
        int maxn = 0;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
            maxn = max(maxn, it->second);
        return wall.size()-maxn;
    }
};
