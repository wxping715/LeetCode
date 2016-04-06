class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        unordered_map<int, int> counter;
        unordered_map<int,int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = counter.find(nums[i]);
            if (it == counter.end()) counter[nums[i]] = 1;
            else {
                if (it->second + 1 > nums.size()/2) return nums[i];
                it->second += 1;
            }
        }
    }
};
