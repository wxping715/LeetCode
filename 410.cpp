/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0, mid;
        for (int num : nums) {
            l = max(l, num);
            r += num;
        }
        
        while (l < r) {
            mid = (r-l)/2 + l;
            if (!split(nums, m, mid)) l = mid+1;
            else r = mid;
        }
        return l;
    }
    
    bool split(vector<int>&nums, int m, int v) {
        int cnt = 1, cur = 0;
        for (int num : nums) {
            cur += num;
            if (cur > v) {
                cur = num;
                cnt++;
            }
            if (cnt > m) return false;
        }
        return true;
    }
};
