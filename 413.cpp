class Solution {
public:

    // my solution, calc the diffenec between items
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> diff;
        for (int i = 1; i < A.size(); i++)
            diff.push_back(A[i]-A[i-1]);
        
        if (diff.size() < 2) return 0;
        int p1 = 0, p2, sum = 0;
        
        for (p2 = 0; p2 < diff.size(); p2++) {
            if (diff[p2] != diff[p1]) {
                sum += (p2-p1)*(p2-p1-1)/2;
                p1 = p2;
            }
        }
        sum += (p2-p1)*(p2-p1-1)/2;
        return sum;
    }
    
    // dp solution
    // dp[i] means the number of slice ending with item[i]
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> dp(A.size(), 0);
        int result = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp[i] = dp[i-1]+1;
            result += dp[i];
        }
        return result;
    }
};
