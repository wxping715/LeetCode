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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        
        int s = intervals[0].start, e = intervals[0].end;
        for (Interval interval : intervals) {
            if (interval.start > e ) {
                ret.push_back(Interval(s,e));
                s = interval.start;
                e = interval.end;
            } else {
                e = max(interval.end, e);
            }
        }
        ret.push_back(Interval(s, e));
        return ret;
    }
    
    bool static cmp(const Interval& i1, const Interval& i2) {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
};
