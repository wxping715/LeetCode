/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size(),1);
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            r[i] = p;
            p *= nums[i];
        }
        
        p = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            r[i] *= p;
            p *= nums[i];
        }
        
        return r;
    }
};
