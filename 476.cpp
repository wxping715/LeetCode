class Solution {
public:

    // my version
    int findComplement(int num) {
        if (num == 0) return 0;
        
        int bits = 0, tnum = num;
        while (tnum) {
            bits++;
            tnum >>= 1;
        }
        cout << bits << endl;
        return (~((unsigned int)num << (32- bits))) >> (32 - bits);
    }
    
    // simplest way
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};
