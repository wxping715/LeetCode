class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        vector<int> inc1(nums.size(), 0), inc2(nums.size(), 0);
        int minx = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > minx) inc1[i] = 1;
            else if (nums[i] < minx) minx = nums[i];
        }
        
        int maxx = INT_MIN;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < maxx) inc2[i] = 1;
            else if (nums[i] > maxx) maxx = nums[i];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (inc1[i] == 1 && inc2[i] == 1) return true;
        }
        return false;
    }
};
