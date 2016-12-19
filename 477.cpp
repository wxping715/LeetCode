class Solution {
public:

    // O(N^2)
    // int totalHammingDistance(vector<int>& nums) {
    //     int ret = 0;
    //     for (int i = 0; i < nums.size(); i++) 
    //         for (int j = i+1; j < nums.size(); j++) {
    //             int a = nums[i]^nums[j];
    //             while (a) {
    //                 ret++;
    //                 a &= (a-1);
    //             }
    //         }
    //     return ret;
    // }
    
    // O(32*N)
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, freq[32] = {0};
        for (int i = 0; i < 32; i++) 
            for (int num : nums) {
                freq[i] += (num >> i)&1;
            }
        
        for (int i = 0; i < 32; i++)
            ret += freq[i]*(nums.size() - freq[i]);
        return ret;
    }
};
