/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if (3*k > nums.size())
            return {};
        
        // compute sum array
        vector<int> sum(nums.size()-k+1, 0);
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (i >= k-1) {
                sum[i-k+1] = s;
                s -= nums[i-k+1];
            }
        }
        
        int maxIdx = 0;
        vector<int> leftMax(nums.size()-k+1, 0), rightMax(nums.size()-k+1, 0);
        // compute left maximum
        for (int i = 0; i < sum.size(); i++) {
            if (sum[maxIdx] < sum[i])
                maxIdx = i;
            leftMax[i] = maxIdx;
        }
        
        maxIdx = sum.size()-1;
        // compute right maximum
        for (int i = sum.size()-1; i >= 0; i--) {
            if (sum[maxIdx] <= sum[i])
                maxIdx = i;
            rightMax[i] = maxIdx;
        }
        
        int maxv = 0;
        vector<int> indices;
        // iterate the mid index
        for (int i = k; i+2*k <= nums.size(); i++) {
            int current = sum[i] + sum[leftMax[i-k]] + sum[rightMax[i+k]];
            if (current > maxv) {
                maxv = current;
                indices = {leftMax[i-k], i, rightMax[i+k]};
            }
        }
        return indices;
    }
};
