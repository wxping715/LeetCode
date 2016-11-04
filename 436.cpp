/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> lps;
        unordered_map<int, int> index;
        
        for (int i = 0; i < intervals.size(); i++) {
            index[intervals[i].start] = i;
            lps.push_back(intervals[i].start);
        }
        sort(lps.begin(), lps.end());
        
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int>::iterator it = lower_bound(lps.begin(), lps.end(), intervals[i].end);
            if (it == lps.end()) res.push_back(-1);
            else res.push_back(index[*it]);
        }
        return res;
    }
};
