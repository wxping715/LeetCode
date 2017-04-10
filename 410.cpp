class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0, mid;
        for (int num : nums) {
            l = max(l, num);
            r += num;
        }
        
        while (l < r) {
            mid = (r-l)/2 + l;
            if (!split(nums, m, mid)) l = mid+1;
            else r = mid;
        }
        return l;
    }
    
    bool split(vector<int>&nums, int m, int v) {
        int cnt = 1, cur = 0;
        for (int num : nums) {
            cur += num;
            if (cur > v) {
                cur = num;
                cnt++;
            }
            if (cnt > m) return false;
        }
        return true;
    }
};
