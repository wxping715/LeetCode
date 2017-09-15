/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    
    /*
    * cases: 
    *     1. [-1,-2,-3,-4,-7]  168
    *     2. [2,3,-2,-4]  48
    *     3. [2,3,-2,4]   6
    */
    int maxProduct(vector<int>& nums) {
        int r = INT_MIN, minv = 1, maxv = 1;
        for (int num : nums) {
            int minv_t = min(num, min(num*maxv, num*minv));
            int maxv_t = max(num, max(num*maxv, num*minv));
            minv = minv_t;
            maxv = maxv_t;
            r = max(r, maxv);
        }
        return r;
    }
};
