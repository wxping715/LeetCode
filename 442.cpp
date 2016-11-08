class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (auto i: nums) {
            int id = abs(i)-1;
            if (nums[id] < 0) res.push_back(id+1);
            nums[id] = -nums[id];
        }
        return res;
    }
};
