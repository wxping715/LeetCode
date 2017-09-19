/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
*/

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
                ++r;
                if (r < sortedNums.size())
                    hashmap[sortedNums[r].second]++;
            }
        }
        
        return {rl, rr};
    }
};
