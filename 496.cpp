class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> next;
        stack<int> s;
        for (int num : nums) {
            while (!s.empty() && s.top() < num) {
                next[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> res;
        for (int num : findNums) {
            if (next.count(num)) res.push_back(next[num]);
            else res.push_back(-1);
        }
        return res;
    }
};
