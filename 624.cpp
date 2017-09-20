/*
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:

Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:

Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minv1 = INT_MAX, minv2 = INT_MAX, mini1, mini2;
        int maxv1 = INT_MIN, maxv2 = INT_MIN, maxi1, maxi2;
        
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i].front() < minv1) {
                minv2 = minv1;
                mini2 = mini1;
                minv1 = arrays[i].front();
                mini1 = i;
            } else if (arrays[i].front() < minv2) {
                minv2 = arrays[i].front();
                mini2 = i;
            }
            
            if (arrays[i].back() > maxv1) {
                maxv2 = maxv1;
                maxi2 = maxi1;
                maxv1 = arrays[i].back();
                maxi1 = i;
            } else if (arrays[i].back() > maxv2) {
                maxv2 = arrays[i].back();
                maxi2 = i;
            }
        }
        
        if (maxi1 != mini1) return maxv1 - minv1;
        else return max(maxv2-minv1, maxv1-minv2);
    }
};
