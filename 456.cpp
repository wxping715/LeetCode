class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        stack<int> s;
        int maxmin = INT_MIN;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < maxmin) return true;
            while (!s.empty() && nums[i] > s.top()) {
                maxmin = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
