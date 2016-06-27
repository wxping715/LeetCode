class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) return nums1;
        if (nums2.size() == 0) return nums2;
        
        unordered_set<int> hashset(nums1.begin(), nums1.end());
        vector<int> res;
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
            if (hashset.find(*it) != hashset.end()) {
                hashset.erase(*it);
                res.push_back(*it);
            }
        }
        return res;
    }
};
