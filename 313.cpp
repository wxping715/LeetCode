class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0 || primes.size() < 1) return 0;
    
        vector<int> nums(n+1, INT_MAX);
        vector<int> cnt(primes.size(), 0);
        nums[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++) nums[i]=min(nums[i], nums[cnt[j]]*primes[j]);
            for (int j = 0; j < primes.size(); j++) cnt[j] += (nums[i] == nums[cnt[j]]*primes[j]);
        }
        return nums[n-1];
    }
};
