class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int,int> next;
        bool first = true;
        vector<int> res(nums.size(), -1);
        stack<int> s;
        
        int i = 0;
        while (i < nums.size()) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
            
            if ((i+1 == nums.size()) && first) {
                i = 0;
                first = false;
            } else i++;
        }
        return res;
    }
};
