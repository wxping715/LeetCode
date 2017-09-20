/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
    
    int distance(pair<int,int>& p1, pair<int,int>& p2) {
        return (p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second)*(p2.second - p1.second);
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int r = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> hashmap;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int dis = distance(points[i], points[j]);
                hashmap[dis]++;
            }
            
            for (auto it : hashmap) {
                int n = it.second;
                r += n*(n-1);
            }
        }
        return r;
    }
};
