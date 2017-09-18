/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

class Solution {
public:
    
    int findLHS(vector<int>& nums) {
        map<int, int> hashmap;
        for (int num : nums)
            hashmap[num]++;
        
        int r = 0;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            auto nit = next(it);
            if (nit == hashmap.end()) break;
            if (it->first + 1 != nit->first) continue;
            r = max(r, it->second + nit->second);
        }
        return r;
    }
};
