class Solution {
public:

    // solution using multiset
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        #define LL long long int
        int res = 0;
        LL cur = 0;
        multiset<LL> mset;
        mset.insert(0);
        for (int num : nums) {
            cur += num;
            res += std::distance(mset.lower_bound(cur-upper), mset.upper_bound(cur-lower));
            mset.insert(cur);
        }
        return res;
    }
    
    //solution using binary search tree
    //todo
};
