class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum = vector<int>(nums.size(), 0);
        onums = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int added = val - onums[i];
        onums[i] = val;
        i++;
        while (i <= onums.size()) {
            sum[i-1] += added;
            i += lowbit(i);
        }
    }

    int sumRange(int i, int j) {
        return csum(j) - csum(i) + onums[i];
    }

    int csum(int i) {
        int res = 0;
        i++;
        while (i > 0) {
            res += sum[i-1];
            i -= lowbit(i);
        }
        return res;
    }

    int lowbit(int x) {
        return x&(-x);
    }
private:
    vector<int> sum;
    vector<int> onums;
};
