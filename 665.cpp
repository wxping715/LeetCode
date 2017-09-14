/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 
4
 to 
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/

class Solution {
public:
    
    /*
    * 1. there is at most a valley
    * 2. modify by increasing valley or decreasing left
    *    2.1 increase valley, left must be smaller or equal to right
    *    2.2 decrease left, the pre value must be smaller or equal to valley
    */
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, k = 0, p = -1;
        for (int i = 0; i+1 < nums.size(); i++)
            if (nums[i] > nums[i+1]) {
                cnt++;
                k = i+1;
                if (i-1 >= 0) p = nums[i-1];
            }
        
        if (cnt > 1) return false;
        if (cnt == 0) return true;
        return (k+1 >= nums.size() || nums[k-1] <= nums[k+1] || p <= nums[k]);
    }
};
