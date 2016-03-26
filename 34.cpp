class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        
        res[0] = bsearch(nums, target, true);
        if (res[0] == -1) return res;
        res[1] = bsearch(nums, target, false);
    }
    
    int bsearch(vector<int>& nums, int target, bool left) {
        int l = 0, r = nums.size()-1, mid;
        while(l <= r) {
            mid = (r-l)/2 + l;
            
            if (left) {
                if ((nums[mid] == target) && (mid-1 < l || nums[mid-1] != target)) return mid;
                else if (nums[mid] >= target) r = mid - 1;
                else l = mid + 1;
            } else {
                if ((nums[mid] == target) && (mid+1 > r || nums[mid+1] != target)) return mid;
                else if (nums[mid] <= target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
