class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        unordered_map<int, int> counter;
        unordered_map<int,int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = counter.find(nums[i]);
            if (it == counter.end()) counter[nums[i]] = 1;
            else {
                if (it->second + 1 > nums.size()/2) return nums[i];
                it->second += 1;
            }
        }
    }
};


class Solution {
public:
    /*
    * one-pass soluation
    * cnt represents the counter difference between result and the second result, if cnt == 0 , it means those numbers before has the same counter, so it's the time to remove those numbers and find the result from the remained elements.
    */
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int cnt = 1, res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) res = nums[i];
            if (res == nums[i]) cnt++;
            else cnt--;
        }
        return res;
    }
};
