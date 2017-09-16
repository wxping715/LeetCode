/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

class Solution {
public:
    
    // [part 1] [part 2] [part 3]
    // find the boundary of part2
    // left: the last value larger than minmum of right
    // right: the last value smaller that the maximum of left
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, r = -1;
        int minv = INT_MAX, maxv = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < maxv)
                r = i;
            maxv = max(nums[i], maxv);
        }
        
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] > minv)
                l = i;
            minv = min(minv, nums[i]);
        }
        
        if (l == -1 || r == -1) return 0;
        return r-l+1;
    }
};
