class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (true) {
            if (n == 1) return true;
            if (hash.find(n) != hash.end()) return false;
            
            hash.insert(n);
            int n1 = 0;
            while (n) {
                n1 += (n%10)*(n%10);
                n /= 10;
            }
            n = n1;
        }
        return false;
    }
};
