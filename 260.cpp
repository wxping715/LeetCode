class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xXor = 0;
        for (int i = 0; i < nums.size(); i++)
            xXor ^= nums[i];
        
        int lowbit = xXor & -xXor;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
             if (nums[i] & lowbit)
                a ^= nums[i];
        }
        b = a ^ xXor;
        return vector<int>{a,b};
    }
};
