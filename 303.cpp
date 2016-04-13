class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        sums.resize(nums.size()+1);
        partial_sum(nums.begin(), nums.end(), sums.begin()+1);
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};  


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
