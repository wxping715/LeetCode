class Solution {
public:

    // negative integer to unsigned int saving the original bits
    // be mind: 0
    string toHex(int num) {
        unsigned int n = num;
        string hex = n == 0 ? "0" : "";
        while (n) {
            int r = n%16;
            char ch = r < 10 ? r+'0' : 'a'+(r-10);
            hex.push_back(ch);
            n >>= 4;
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};
