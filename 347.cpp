class Solution {
public:
    /*
    * O(NlogK) algorithms:
    * 1. firstly, scan the nums and count the frequency of numbers using hash_map, O(N)
    * 2. using the heap of size k to find the k frequent elements.
    */
    typedef pair<int, int> mypair;
    
    class Compare {
        public:
        bool operator() (mypair n1, mypair n2) {
            return n1.second > n2.second;
        }  
    };
    
    // typedef priority_queue<mypair> pqueue;
    typedef priority_queue<mypair, vector<mypair>, Compare> pqueue;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        unordered_map<int, int>::iterator it;
        for (int i = 0;i < nums.size(); i++) {
            it = cnt.find(nums[i]);
            if (it == cnt.end()) cnt[nums[i]] = 1;
            else it->second += 1;
        }
        
        pqueue q;
        for (it = cnt.begin(); it != cnt.end(); it++) {
            cout << it->first << " " << it->second << endl;
            if (q.size() < k) q.push(make_pair(it->first, it->second));
            else {
                q.push(make_pair(it->first, it->second));
                q.pop();
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
