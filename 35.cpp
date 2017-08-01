/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l+r)/2;
            if (nums[m] < target) l = m+1;
            else r = m;
        }
        
        if (l+1 == nums.size() && nums[l] < target) l++;
        return l;
    }
};
