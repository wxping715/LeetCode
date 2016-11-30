class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        
        long long sum = 0, nsum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            nsum += i*A[i];
        }
        
        int n = A.size();
        long maxv = nsum;
        for (int i = 1; i <= n; i++) {
            nsum = nsum - A[n-i]*n + sum;
            // cout << nsum << endl;
            if (nsum > maxv) maxv = nsum;
        }
        return ()maxv;
    }
};
