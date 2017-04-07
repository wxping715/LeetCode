class Solution {
public:
    
    /*
    * my solution
    */
    int rangeBitwiseAnd(int m, int n) {
        unsigned int offset = 1;
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            offset = 1 << i;
            if (!(m >> i)) break;
        
            // at least one bit is zero
            if (!(m&offset) || !(n&offset)) continue;
            // it means there will be one zero in this place
            else if (m+offset > n) res += offset;
        }
        return res;
    }
    
    /*
    * simplest way, find prefix of m and n
    */
    int rangeBitwiseAnd(int m, int n) {
        int offset = INT_MAX;
        while ((m&offset) != (n&offset)) offset <<= 1;
        return m&offset;
    }
};
