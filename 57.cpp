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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s = newInterval.start, e = newInterval.end;
        vector<Interval> ret;
        
        int i = 0;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < s) ret.push_back(intervals[i]);
            else if (intervals[i].start > e) break;
            else {
                s = min(s, intervals[i].start);
                e = max(e, intervals[i].end);
            }
        }
        ret.push_back(Interval(s, e));
        for (i; i < intervals.size(); i++) 
            ret.push_back(intervals[i]);
        return ret;
    }
};
