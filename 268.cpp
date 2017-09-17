/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    
    // array method
    // mind: -0 is equal to 0
    int missingNumber(vector<int>& nums) {
        for (int num : nums) {
            int idx = num < 0 ? -num-1 : num;
            if (idx < nums.size()) {
                if (nums[idx] >= 0)
                    nums[idx] = -nums[idx]-1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= 0)
                return i;
        return nums.size();
    }
    
    //math method
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        return n*(n+1)/2 - sum;
    }
    
    /*
    * bit compution
    * 2n+1 numbers with one number is once, others are twice
    */
    int missingNumber(vector<int>& nums) {
        int x = 0, n = nums.size();
        for (int i = 0;i < n;i++) {
            x ^= nums[i]^i;
        }
        x ^= n;
        return x;
    }
};
