class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int l = 0; l < col; l++) {
            vector<int> sums(row, 0);
            for (int s = l; s < col; s++) {
                for (int i = 0; i < row; i++)
                    sums[i] += matrix[i][s];
            
                set<int> pset;
                pset.insert(0);
                int cur = 0;
                for (int sum : sums) {
                    cur += sum;
                    auto it = pset.lower_bound(cur-k);
                    if (it != pset.end()) res = max(res, cur-*it);
                    pset.insert(cur);
                }
            }
        }
        return res;
    }
};
