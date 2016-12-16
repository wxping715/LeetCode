/*Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?*/

class Solution {
public:

    // O(N^2)
    // int maxSubArrayLen(vector<int>& nums, int k) {
    //     int res = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         int sum = 0;
    //         for (int j = i; j < nums.size(); j++) {
    //             sum += nums[j];
    //             if (sum == k)
    //                 res = max(res, j-i+1);
    //         }
    //     }
    //     return res;
    // }
    
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) res = max(res, i+1);
            else if (hashmap.find(sum-k) != hashmap.end())
                res = max(res, i-hashmap[sum-k]);
            if (hashmap.find(sum) == hashmap.end())
                hashmap[sum] = i;
        }
        return res;
    }
};
