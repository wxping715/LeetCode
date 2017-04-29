class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        k -= 1;
        while (k > 0) {
            int count = 0;
            for (long s = res, e = res+1; s <= n; s *= 10, e *= 10) {
                count += min((long)(n+1), e) - s;
            }
            cout << res << " " << count << endl;
            
            if (count <= k) {
                res++;
                k -= count;
            } else {
                res *= 10;
                k -= 1;
            }
        }
        return res;
    }
};
