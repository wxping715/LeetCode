/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int l = leftSearch(nums, target);
		if (l == -1) return {-1, -1};
		
		int r = rightSearch(nums, target);
		return {l,r};
    }
	
	int leftSearch(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1;
		while (l < r) {
			int m = (l+r)/2;
			if (nums[m] >= target) r = m;
			else l = m+1;
		}
		return nums[l] == target ? l : -1;
	}
	
	int rightSearch(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1;
		while (l < r) {
			// move a position to right
			int m = (l+r)/2+1;
			if (nums[m] <= target) l = m;
			else r = m-1;
		}
		return nums[l] == target ? l : -1;
	} 
};
