class Solution {
public:
    
    typedef pair<vector<int>::iterator, int> Node;
    struct Comparsion {
        bool operator() (Node n1, Node n2) {
            return *n1.first > *n2.first;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // sort numbers
        priority_queue<Node, vector<Node>, Comparsion> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i].empty())
                pq.push(make_pair(nums[i].begin(), i));
        }
        
        vector<pair<int, int>> sortedNums;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            
            sortedNums.emplace_back(*cur.first, cur.second);
            
            cur.first++;
            if (cur.first != nums[cur.second].end())
                pq.push(make_pair(cur.first, cur.second));
        }
        
        int l = 0, r = -1, rl = sortedNums.front().first, rr = sortedNums.back().first;
        unordered_map<int, int> hashmap;
        while (r < (int)sortedNums.size()) {
            if (hashmap.size() == nums.size()) {
                if ((sortedNums[r].first - sortedNums[l].first) < (rr - rl)) {
                    rr = sortedNums[r].first;
                    rl = sortedNums[l].first;
                }
                
                hashmap[sortedNums[l].second]--;
                if (hashmap[sortedNums[l].second] == 0)
                    hashmap.erase(sortedNums[l].second);
                l++;
            } else {
                hashmap[sortedNums[++r].second]++;
            }
        }
        
        return {rl, rr};
    }
};
