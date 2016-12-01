class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, next = 0;
        while (i < data.size()) {
            unsigned int octet = data[i++] & 0xff;
            // cout << (0xe0 & octet == 0xc0) << endl;
            if ((0xf8 & octet) == 0xf0) next = 3;
            else if ((0xf0 & octet) == 0xe0) next = 2;
            else if ((0xe0 & octet) == 0xc0) next = 1;
            else if ((0x80 & octet) == 0x00) next = 0;
            else return false;
            
            // cout << next << endl;
            while (next--) {
                if (i >= data.size()) return false;
                unsigned int tbits = data[i++] & 0xff & 0xc0;
                // cout << tbits << endl;
                if (tbits != 0x80) return false;
            }
        }
        return true;
    }
};
