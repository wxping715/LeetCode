/*Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

Show Company Tags
Show Tags
Show Similar Problems*/


class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret = 0, p1, p2, p3;
        sort(nums.begin(), nums.end());
        for (int p1 = 0; p1+2 < nums.size(); p1++) {
            p2 = p1+1, p3 = nums.size()-1;
            while (p2 < p3) {
                if (nums[p1]+nums[p2]+nums[p3] < target) {
                    ret += p3-p2;
                    p2++;
                }
                else p3--;
            }
        }
        return ret;
    }
};
