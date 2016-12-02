/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false. */


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

    // test cases: [[8,11],[17,20],[17,20]], repeated intervals
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1].start <= intervals[i].start && intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }
    
    static bool cmp(const Interval& a, const Interval& b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
};
