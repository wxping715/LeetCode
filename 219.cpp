class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hmap;
        unordered_map<int,int>::iterator it;
        
        for(int i = 0;i < nums.size();i++){
            it = hmap.find(nums[i]);
            if(it != hmap.end()){
                if(i - (*it).second <= k) return true;   
            }
            hmap[nums[i]] = i;
        }
        return false;
    }
};
