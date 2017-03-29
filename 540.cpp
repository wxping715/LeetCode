class Solution {
public:
    /*
    * recursive version
    */
    // int singleNonDuplicate(vector<int>& nums) {
    //     return find(nums, 0, nums.size()-1);
    // }
    
    // int find(vector<int>& nums, int s, int e) {
    //     if (s > e) return INT_MIN;
    //     // need to clarify
    //     if (s == e) return nums[s];
        
    //     int mid = (e-s)/2+s, le, rs;
    //     if (mid+1 <= e && nums[mid] == nums[mid+1]) le = mid-1, rs = mid+2;
    //     else if (mid-1 >= s && nums[mid] == nums[mid-1]) le = mid-2, rs = mid+1;
    //     else return nums[mid];
        
    //     int res = find(nums , s, le);
    //     if (res != INT_MIN) return res;
    //     return find(nums, rs, e);
    // }
    
    
    /*
    * iterative version
    */
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        while (l < r) {
            mid = (r-l)/2+l;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid+1]) l = mid+2;
                else r = mid - 2;
            } else {
                if (nums[mid] == nums[mid+1]) r = mid -1;
                else l = mid + 1;
            }
        }
        return nums[l];
    }
};
