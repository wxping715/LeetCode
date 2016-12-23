/*Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int cur = lower;
        bool flow = false;
        for (int num : nums) {
            if (num < cur) continue;
            else if (num > cur) {
                res.push_back(generate(cur, num-1));
            }
            
            if (num > 0 && num+1 < 0) {
                flow = true;
                cur = num;
            } else {
                cur = num+1;
            }
        }
        if (!flow && upper >= cur) res.push_back(generate(cur, upper));
        return res;
    }
    
    string generate(int eval, int rval) {
        if (rval == eval) return to_string(eval);
        else return to_string(eval)+"->"+to_string(rval);
    }
};
