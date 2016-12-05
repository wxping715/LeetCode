class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return -1;
        int n = matrix[0].size();
        if (n == 0) return -1;
        
        int l = matrix[0][0], r = matrix[m-1][n-1], mid;
        while (l <= r) {
            mid = (r-l)/2 + l;
            int idx = find(matrix, m, n, mid);
        
            if (idx < k) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
    
    int find(vector<vector<int>> &matrix, int m, int n, int v) {
        int i = m-1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] > v) {
                i--;
            } else {
                j++;
                res += i+1;
            }
        }
        return res;
    }
};
