/*Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at y = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.*/


struct hashFunc {
    size_t operator()(const pair<int, int> &point) const {
        return hash<int>()(point.first) ^ (hash<int>()(point.second) << 1) >> 1;
    }
};

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        
        unordered_set<pair<int, int>, hashFunc> hashmap;
        int minx = points[0].first, maxx = points[0].first;
        for (auto point : points) {
            hashmap.insert(point);
            minx = min(point.first, minx);
            maxx = max(point.first, maxx);
        }

        for (auto point : points) {
            int nx = minx+maxx-point.first;
            auto npoint = make_pair(nx, point.second);
            if (hashmap.find(npoint) == hashmap.end())
                return false;
        }
        return true;
    }
};
