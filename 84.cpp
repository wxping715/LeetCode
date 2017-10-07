/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

// Explaination: 
// http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

class Solution {
public:
    
    // O(N^2)
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int l = 0; l < heights.size(); l++) {
            int m = heights[l];
            for (int r = l; r < heights.size(); r++) {
                m = min(m, heights[r]);
                res = max(res, (r-l+1)*m);
            }
        }
        return res;
    }
    
    // O(NLogN)
    // Divide and Conqur
    
    // O(N)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int i = 0, res = 0;
        
        while (!s.empty() || i < heights.size()) {
            if (i < heights.size() && (s.empty() || heights[s.top()] <= heights[i]))
                s.push(i++);
            else {
                int j = s.top();
                s.pop();
                res = max(res, (heights[j] * (s.empty() ? i : i-s.top()-1)));
            }
        }
        return res;
    }
};
