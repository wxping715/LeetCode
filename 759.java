/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start,int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
    // solution 1
//     public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
//         List<int[]> points = new ArrayList<>();
//         for (List<Interval> intervals : schedule) {
//             for (Interval interval : intervals) {
//                 points.add(new int[]{interval.start, 0});
//                 points.add(new int[]{interval.end, 1});
//             }
//         }
//         Collections.sort(points, (a, b)-> {
//             if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
//             return Integer.compare(a[1], b[1]);
//         });
        
//         List<Interval> results = new ArrayList<>();
//         int prev = -1, concurrency = 0;
//         for (int[] interval : points) {
//             if (concurrency == 0 && prev != -1) {
//                 results.add(new Interval(prev, interval[0]));
//             }
//             concurrency += interval[1] == 0 ? 1 : -1;
//             if (concurrency == 0) prev = interval[0];
//         }
//         return results;
//     }
    
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> points = new ArrayList<>();
        for (List<Interval> intervals : schedule) {
            points.addAll(intervals);
        }
        Collections.sort(points, (a, b) -> a.start - b.start);
        Interval curr = points.get(0);
        List<Interval> results = new ArrayList<>();
        for (Interval interval : points) {
            if (curr.end < interval.start) {
                results.add(new Interval(curr.end, interval.start));
                curr = interval;
            } else {
                curr.end = Math.max(curr.end, interval.end);
            }
        }
        return results;
    }
}
