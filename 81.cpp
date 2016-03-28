class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (r-l)/2 + l;
            
            if(nums[mid] == target) return true;
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else if (nums[l] == nums[mid]) {
                l++;
            }
            else {
                if (nums[mid+1] <= target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
