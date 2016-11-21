class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 1, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            if (rand()%cnt++ == 0) res = i;
        } 
        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
