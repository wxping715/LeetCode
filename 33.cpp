/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
        	int m = (l+r)/2;
        	if (nums[m] == target) return m;
            // case 1: should search in right
        	else if (nums[l] <= nums[m] && nums[l] <= target && nums[m] >= target)
        		r = m-1;
            // case 2: should search in right
        	else if (nums[m] <= nums[r] && (nums[m] > target || nums[r] < target))
        		r = m-1;
        	else
        		l = m+1;
        }
        return -1;
    }
};
