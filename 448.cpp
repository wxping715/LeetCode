class Solution {
public:

    // O(n) time, O(n) space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int freq[nums.size()+1] = {0};
        for (auto it = nums.begin(); it != nums.end(); it++)
            freq[*it]++;
        for (int i = 1; i <= nums.size(); i++)
            if (!freq[i])
                res.push_back(i);
        return res;
    } 
    
    // O(n) time, O(1) space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto i : nums) {
            int id = abs(i)-1;
            nums[id] = nums[id] > 0 ? -nums[id] : nums[id];
        }
            
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                res.push_back(i+1);
        return res;
    }
};
