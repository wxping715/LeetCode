class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int p1 = -1, p2;
        for (int i = nums.size()-2; i >= 0; i--)
            if (nums[i] < nums[i+1]) {
                p1 = i;
                break;
            }
            
        if (p1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        p2 = p1+1;
        // mind that nums[i] > nums[p1] && nums[i] <= nums[p2]
        for (int i = p2; i < nums.size(); i++)
            if (nums[i] > nums[p1] && nums[i] <= nums[p2])
                p2 = i;
        
        swap(nums[p1], nums[p2]);
        reverse(nums.begin()+p1+1, nums.end());
    }
};
