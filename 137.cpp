class Solution {
public:

    /*
    * O(32*n)
    */
    int singleNumber(vector<int>& nums) {
        vector<int> dnums(32, 0);
        for (int num : nums) {
            int i = 0;
            unsigned int t = (unsigned int)num;
            while (t) {
                if (t&1) dnums[i]++;
                t >>= 1;
                i++;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (dnums[i]%3) res |= (1 << i);
        }
        return res;
    }
};
