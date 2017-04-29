class Solution {
public:

    /*
    * my failed solution
    */
    /**
    void comb(vector<int>& nums, vector<bool>& hash, int &sum, int cur, int re, int n) {
        if (re == 0) {
            if (sum <= n) hash[sum] = true;
            return;
        }
        
        for (int c = cur; c+re <= nums.size(); c++) {
            sum += nums[c];
            comb(nums, hash, sum, c+1, re-1, n);
            sum -= nums[c];
        }
    }

    int minPatches(vector<int>& nums, int n) {
        set<int> missing_numbers;
        vector<bool> hash(n+1, false);
        int res = 0, sum = 0;
        
        // combinations
        hash[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            sum = 0;
            comb(nums, hash, sum, 0, i, n);
        }
        for (int i = 1; i <= n; i++)
            if (!hash[i]) missing_numbers.insert(i);
        
        // patch
        while (!missing_numbers.empty()) {
            int cur = *(missing_numbers.begin());
            res++;
            
            vector<int> need_delete;
            for (auto it = missing_numbers.rbegin(); it != missing_numbers.rend(); it++) {
                if (hash[*it - cur]) {
                    hash[*it] = true;
                    need_delete.push_back(*it);
                }
            }
            
            for (int num : need_delete) {
                missing_numbers.erase(num);
            }
        }
        return res;
    }
    **/
    
    /*Let miss be the smallest sum in [0,n] that we might be missing. Meaning we already know we can build all sums in [0,miss). Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in [0,miss+num). If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach.*/
    int minPatches(vector<int>& nums, int n) {
        long missed = 1;
        int res = 0, i = 0;
        sort(nums.begin(), nums.end());
        while (missed <= n) {
            if (i < nums.size() && nums[i] <= missed) {
                missed += nums[i++];
            }
            else {
                missed += missed;
                res ++;
            }
        }
        return res;
    }
};
