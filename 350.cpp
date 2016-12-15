class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int num : nums1) 
            hashmap[num]++;
        vector<int> res;
        for (int num : nums2) {
            auto it = hashmap.find(num);
            if (it != hashmap.end() && it->second > 0) {
                res.push_back(num);
                it->second--;
            }
        }
        return res;
    }
};
