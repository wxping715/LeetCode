class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::multiset<int> myset;
        int res = 0, cur = 0;
        
        myset.insert(0);
        for (int num : nums) {
            cur += num;
            res += myset.count(cur-k);
            myset.insert(cur);
        }
        return res;
    }
};
