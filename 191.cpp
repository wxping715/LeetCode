class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += 1;
            n = n&(n-1);
        }
        return res;
    }
};
