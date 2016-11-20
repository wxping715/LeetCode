class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minv = INT_MAX;
        for (int n: nums) sum += n;
        for (int n: nums) minv = min(minv, n);
        return sum - nums.size()*minv;
    }
};
