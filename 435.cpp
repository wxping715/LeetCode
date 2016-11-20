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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int last = intervals[0].end, res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (last > intervals[i].start) {
                res++;
                last = min(last, intervals[i].end);
            } else
                last = max(last, intervals[i].end);
        }
        return res; 
    }
    
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};
