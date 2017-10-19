/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    
    struct Comparsion {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };
    
    
    // NlogK
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int num : nums)
            hashmap[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparsion> pq;
        for (auto it : hashmap) {
            pq.push({it.first, it.second});
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    // O(n) time, O(n) space
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int num : nums)
            hashmap[num]++;
        
        vector<vector<int>> bucket(nums.size()+1, vector<int>(0,0));
        for (auto it : hashmap)
            bucket[it.second].push_back(it.first);
        
        vector<int> res;
        for (int i = nums.size(); i >= 1; i--) {
            if (k == 0) break;
            int size = min(k, (int)bucket[i].size());
            for (int j = 0; j < size; j++)
                res.push_back(bucket[i][j]);
            k -= size;
        }
        return res;
    }
};
