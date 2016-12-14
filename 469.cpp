/*Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:*/

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        if (points.size() < 3) return false;
        points.push_back(points[0]);
        points.push_back(points[1]);
        
        int flag = -2;
        for (int i = 0; i+2 < points.size(); i++) {
            int res = cross(points[i], points[i+1], points[i+2]);
            if (res == 0) continue;
            if (flag == -2) flag = res < 0 ? -1 : 1;
            else if (flag*res < 0) return false;
        }
        return true;
    }
    
    int cross(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
        return (p1[0]-p2[0])*(p2[1]-p3[1]) - (p1[1]-p2[1])*(p2[0]-p3[0]);
    }
};
