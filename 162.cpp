class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<bool> inc(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
            if (i == 0 || nums[i] > nums[i-1])
                inc[i] = true;
        for (int i = nums.size()-1; i >= 0; i--)
            if ((i == nums.size()-1 || nums[i] > nums[i+1]) && inc[i])
                return i;
        return -1;
    }
};
