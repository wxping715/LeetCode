/*
A positive integer is magical if it is divisible by either A or B.

Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7.
*/

class Solution {
    
    // my solution
//     public int nthMagicalNumber(int N, int A, int B) {
//         if (A > B) return nthMagicalNumber(N, B, A);
//         final long MOD = 1000000007;
        
//         int gcd = gcd(A, B);
//         int lcm = A * B / gcd;
//         int period = lcm/A + lcm/B - 1;
        
//         long ans = (N/period * (long)lcm) % MOD;
//         N = N % period;
//         long at = 0, bt = 0;
//         if (N == 0) return (int)ans;
        
//         while ((N--) > 0) {
//             if (at + A <= bt + B) at += A;
//             else bt += B;
//         }
        
//         return (int)((ans + Math.max(at, bt)) % MOD);
//     }
    
    private int gcd(int a, int b) {
        if (b % a == 0) return a;
        return gcd(b%a, a);
    }
    
    public int nthMagicalNumber(int N, int A, int B) {
        int gcd = gcd(A, B), lcm = A * B / gcd;
        long l = 2, r = (long)1e14;
        while (l < r) {
            long m = (l + r) / 2;
            if (m/A+m/B-m/lcm < N) l = m+1;
            else r = m;
        }
        return (int)(l % (long)1000000007);
    }
}
