/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int num : nums) {
            while (num > 0 && num <= nums.size() && nums[num-1] != num) {
                int t = nums[num-1];
                nums[num-1] = num;
                num = t;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i+1)
                return i+1;
        return nums.size()+1;
    }
};
