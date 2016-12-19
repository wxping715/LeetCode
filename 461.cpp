class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0, z = x^y;
        while (z) {
            ret++;
            z &= (z-1);
        }
        return ret;
    }
};
