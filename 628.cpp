/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
class Solution {
public:
    
    /*
    * NlogN
    * 1. sort all numbers
    * 2. compare nums[n-1]*nums[n-2]*nums[n-3] and nums[0]*nums[1]*nums[n-1]
    * 
    * test cases:
    * 1. [1,2,4,5]  k = 0, 2*4*5
    * 2. [-5,-3,-2,-1]  k = -1, -3*-2*-1 = -6
    * 3. [-3,1,2,3] k = 1,  1*2*3 = 6
    * 4. [-6,-4,1,2,3] k = 2 -6*-4*3=72
    * 5. [-3,-2,-1,5,6] k = 3  -3*-2*6
    */
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
    
    // single scan, find the smallest 2 and largest 3
    // 
};
