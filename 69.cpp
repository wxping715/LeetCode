/*
Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {
public:
    int mySqrt(int x) {
        typedef long long int LL;
        
        LL l = 0, r = min(x, 50000);
        while (l <= r) {
            LL m = (r+l)/2;
            if (m*m <= x && (m+1)*(m+1) > x) return m;
            else if (m*m >= x) r = m-1;
            else l = m+1;
        }
        return 0;
    }
};
