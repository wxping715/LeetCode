class Solution {
public:
    /*
    * exception using average [1, 0, 0, 8, 6]
    */
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int medium = nums[nums.size()/2], res = 0;
        for (int n: nums) res += abs(n - medium);
        return res;
    }
};
