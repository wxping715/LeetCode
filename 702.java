/*
702. Search in a Sorted Array of Unknown Size
Medium

241

19

Add to List

Share
Given an integer array sorted in ascending order, write a function to search target in nums.  If target exists, then return its index, otherwise return -1. However, the array size is unknown to you. You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

 

Example 1:

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

*/

class Solution {
    public int search(ArrayReader reader, int target) {
        int hi = 1;
        while (reader.get(hi) < target)
            hi <<= 1;
        int low = hi >> 1;
        
        int l = low, r = hi, m;
        while (l <= r) {
            m = (r-l)/2+l;
            if (reader.get(m) == target) return m;
            else if (reader.get(m) > target) r = m-1;
            else l = m+1;
        }
        return -1;
    }
}
