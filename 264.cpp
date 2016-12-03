class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        int l1 = 0, l2 = 0, l3 = 0;
        
        vector<int> res(n, 0);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = min(res[l1]*2, min(res[l2]*3, res[l3]*5));
            if (res[i] == res[l1]*2) l1++;
            if (res[i] == res[l2]*3) l2++;
            if (res[i] == res[l3]*5) l3++;
        }
        return res[n-1];
    }
};
