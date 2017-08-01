/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l+r)/2;
        	// must be increase, decrese
        	if (nums[m] > nums[r]) l = m+1;
        	else r = m;
        }
        return nums[l];
    }
};
