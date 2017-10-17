/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
    
    // NlogN
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0;
        for (int i = 0; i+2 < nums.size(); i++) {
            if (nums[i] == 0) continue;
            for (int j = i+1; j+1 < nums.size(); j++) {
                auto it = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                r += it - nums.begin()-j-1;
            }
        }
        return r;
    }
};
