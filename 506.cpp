class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push(make_pair(nums[i], i));
        
        vector<string> ranks(nums.size(), "");
        int rank = 1;
        string cur = "";
        while (!pq.empty()) {
            if (rank > 3) cur = to_string(rank);
            else if (rank == 1) cur = "Gold Medal";
            else if (rank == 2) cur = "Silver Medal";
            else cur = "Bronze Medal";
            
            int idx = pq.top().second;
            pq.pop();
            ranks[idx] = cur;
            rank++;
        }
        return ranks;
    }
};
