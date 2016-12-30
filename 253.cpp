/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/
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

    //solution1
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
    
    // solution 2
    int minMeetingRooms(vector<Interval>& intervals) {
        int ret = 0, cur = 0;
        priority_queue<int> q;
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.empty()) return 0;
        
        q.push(-intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= -q.top())
                q.pop();
            q.push(-intervals[i].end);
        }
        return q.size();
    }
    
    //solution 3
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (Interval interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int eidx = 0, ret = 0;
        for (int i = 0; i < starts.size(); i++) {
            if (starts[i] < ends[eidx]) ret++;
            else eidx++;
        }
        return ret;
    }
    
    bool static cmp(const Interval& i1, const Interval& i2) {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
};

