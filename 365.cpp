class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x+y >= z && (z % gcd(x, y) == 0));
    }
    
    int gcd(int a, int b) {
        while (b) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }
};
