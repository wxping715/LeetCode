class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(vector<int>(nums.begin(), nums.end()));
        } while (nextPermutation(nums));
        return res;
    }
    
    bool nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        
        int p1 = -1, p2;
        for (int i = nums.size()-2; i >= 0; i--)
            if (nums[i] < nums[i+1]) {
                p1 = i;
                break;
            }
            
        if (p1 == -1) return false;
        
        p2 = p1+1;
        // mind that nums[i] > nums[p1] && nums[i] <= nums[p2]
        for (int i = p2; i < nums.size(); i++)
            if (nums[i] > nums[p1] && nums[i] <= nums[p2])
                p2 = i;
        
        swap(nums[p1], nums[p2]);
        reverse(nums.begin()+p1+1, nums.end());
        return true;
    }
};
