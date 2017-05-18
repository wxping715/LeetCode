class Solution {
public:

    // nlogn solution
    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int> snums(nums.begin(), nums.end());
    //     sort(snums.begin(), snums.end());
        
    //     int l = 0, r = nums.size()-1;
    //     while (l < nums.size() && nums[l] == snums[l]) l++;
    //     while (r >= l && nums[r] == snums[r]) r--;
        
    //     return r-l+1;
    // }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, reversed = false;
        for (int num : nums) {
            if (l == -1 || nums[l] <= num) {
                if (!reversed) l++; 
            } else {
                while (l >= 0 && nums[l] > num) l--;
                reversed = true;
            }
        }
        
        int r = nums.size();
        reversed = false;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (r == nums.size() || nums[r] >= nums[i]) {
                if (!reversed) r--;
            } else {
                while (r < nums.size() && nums[r] < nums[i]) r++;
                reversed = true;
            }
        }
        
        return l < r ? r-l-1 : 0;
    }
};
