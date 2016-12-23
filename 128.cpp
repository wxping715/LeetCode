class Solution {
public:

    // O(NlogN)
    /*int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        
        int cur = nums[0], cnt = 1, res = 1;
        for (int num : nums) {
            if (num == cur) continue;
            else if (num == cur+1) {
                cnt++;
                cur++;
                res = max(res, cnt);
            }
            else {
                cnt = 1;
                cur = num;
            }
        }
        return res;
    }*/
    
    //O(N)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int res = 0;
        for (int num : hash) {
            if (hash.count(num-1) == 0) {
                int m = num+1;
                while (hash.count(m) > 0)
                    m++;
                res = max(res, m-num);
            }
        }
        return res;
    }
};
