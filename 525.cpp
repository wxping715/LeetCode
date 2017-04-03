class Solution {
public:

    /*
    * O(n) space, O(n) time
    */
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0, cnt = 0;
        
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            cnt = nums[i] == 0 ? cnt-1 : cnt+1;
            if (hash.count(cnt) > 0) res = max(res, i-hash[cnt]);
            else hash[cnt] = i;
        }
        return res;
    }
    
    
};
