/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) cur[j] = pre[j];
                else if (j == i) cur[j] = pre[j-1];
                else cur[j] = min(pre[j], pre[j-1]);
                
                cur[j] += triangle[i][j];
                
                // cout << i << " " << j << " " << cur[j] << endl;
            }
            pre = cur;
        }
        
        int minv = INT_MAX;
        for (int i = 0; i < n; i++)
            minv = min(pre[i], minv);
        return minv;
    }
};
