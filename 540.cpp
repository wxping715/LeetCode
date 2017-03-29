class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return find(nums, 0, nums.size()-1);
    }
    
    int find(vector<int>& nums, int s, int e) {
        if (s > e) return INT_MIN;
        // need to clarify
        if (s == e) return nums[s];
        
        int mid = (e-s)/2+s, le, rs;
        if (mid+1 <= e && nums[mid] == nums[mid+1]) le = mid-1, rs = mid+2;
        else if (mid-1 >= s && nums[mid] == nums[mid-1]) le = mid-2, rs = mid+1;
        else return nums[mid];
        
        int res = find(nums , s, le);
        if (res != INT_MIN) return res;
        return find(nums, rs, e);
    }
};
