/*Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.*/

class Solution {
public:

    // O(N^2)
    // int findMaximumXOR(vector<int>& nums) {
    //     int res = 0;
    //     for (int i = 0;i < nums.size(); i++)
    //         for (int j = i+1; j < nums.size(); j++)
    //             res = max(res, nums[i]^nums[j]);
    //     return res;
    // }
    
    // O(N*32)
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            unordered_set<int> prefixs;
            for (int num : nums)
                prefixs.insert(num & mask);
            int candicate = max | (1 << i);
            for (int prefix : prefixs) {
                if (prefixs.count(prefix^candicate)) {
                    max = candicate;
                    break;
                }
            }
        }
        return max;
    }
};
