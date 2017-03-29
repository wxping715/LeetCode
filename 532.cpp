class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> hashnum;
        unordered_set<int> hashpair;
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++)
            hashnum[nums[i]]++;
        
        for (auto it = hashnum.begin(); it != hashnum.end(); it++) {
            if (k == 0) {
                if (hashnum[it->first] > 1) res++;
                continue;
            }
            
            int v = it->first;
            if (hashnum.count(v-k)) {
                if (!hashpair.count(v-k)) res++;
                hashpair.insert(v-k);
            }
            if (hashnum.count(v+k)) {
                if (!hashpair.count(v)) res++;
                hashpair.insert(v);
            }
        }
        
        return res;
    }
};
