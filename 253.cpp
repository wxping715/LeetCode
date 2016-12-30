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
    int minMeetingRooms(vector<Interval>& intervals) {
        int ret = 0, cur = 0;
        priority_queue<int> q;
        sort(intervals.begin(), intervals.end(), cmp);
        for (Interval interval : intervals) {
            while (!q.empty() && -q.top() <= interval.start) {
                q.pop();
                cur--;
            }
            q.push(-interval.end);
            cur++;
            ret = max(ret, cur);
        }
        return ret;
    }
    
    bool static cmp(const Interval& i1, const Interval& i2) {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
};
