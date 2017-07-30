/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        
        int s = nums[0], e = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (e+1 == nums[i])
                e++;
            else {
                if (s == e) res.push_back(to_string(s));
                else res.push_back(to_string(s)+"->"+to_string(e));
                
                s = nums[i];
                e = nums[i];
            }
        }
        res.push_back(s == e ? to_string(s): to_string(s)+"->"+to_string(e));
        return res;
    }
};
