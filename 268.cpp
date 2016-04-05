class Solution {
public:
    /*
    * math method
    */
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        return n*(n+1)/2 - sum;
    }
};

class Solution {
public:
    /*
    * bit compution
    * 2n+1 numbers with one number is once, others are twice
    */
    int missingNumber(vector<int>& nums) {
        int x = 0, n = nums.size();
        for (int i = 0;i < n;i++) {
            x ^= nums[i]^i;
        }
        x ^= n;
        return x;
    }
};
