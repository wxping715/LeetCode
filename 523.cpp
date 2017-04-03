class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 真是坑！
        
        k = k < 0 ? -k : k;
        unordered_map<int,int> hash;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) sum %= k;
            
            if (sum == 0 && i > 0) return true;
            else if (hash.count(sum) && i-hash[sum]>1) return true;
            else if (!hash.count(sum)) hash[sum] = i;
        }
        return false;
    }
};
