class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int minv = nums[0], maxv = nums[0];
        for (int num : nums) {
            minv = min(num, minv);
            maxv = max(num, maxv);
        }
        
        int n = nums.size();
        int gap = (int)(ceil((maxv-minv)*1.0/(n-1)));
        if (gap == 0) return 0;
        
        vector<int> bucketsMin(n-1, INT_MAX);
        vector<int> bucketsMax(n-1, INT_MIN);
        for (int num: nums) {
            int idx = (num-minv)/gap;
            bucketsMin[idx] = min(num, bucketsMin[idx]);
            bucketsMax[idx] = max(num, bucketsMax[idx]);
        }
        
        int maxGap = 0, preMax = minv;
        for (int i = 0; i+1 < nums.size(); i++) {
            if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
                continue;
            maxGap = max(bucketsMin[i] - preMax, maxGap);
            preMax = bucketsMax[i];
        }
        maxGap = max(maxGap, maxv-preMax);
        return maxGap;
    }
};
