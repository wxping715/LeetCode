class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() <= 2) return res;
        
        int p1, p2, p3;
        for (int p1 = 0; p1 < nums.size()-2; p1++) {
            if (p1 > 0 && nums[p1] == nums[p1-1]) continue;
            p2 = p1+1, p3 = nums.size() - 1;
            int target = -nums[p1];
            while (p2 < p3) {
                if (nums[p2]+nums[p3] == target) {
                    vector<int> tuple;
                    tuple.push_back(nums[p1]);
                    tuple.push_back(nums[p2]);
                    tuple.push_back(nums[p3]);
                    res.push_back(tuple);
                    p2++;
                    p3--;
                    while (p2 < p3 && nums[p2] == nums[p2-1]) p2++;
                    while (p3 > p2 && nums[p3] == nums[p3+1]) p3--;
                } 
                else if (nums[p2]+nums[p3] < target) p2++;
                else p3--;
            }
        }
        return res;
    }
};
