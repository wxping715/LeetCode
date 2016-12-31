class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = INT_MIN, cnt = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != pre) {
                pre = nums[i];
                cnt = 1;
            } else cnt++;
            
            if (cnt <= 2) nums[k++] = nums[i];
        }
        return k;
    }
};
