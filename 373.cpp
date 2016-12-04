class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        
        if (nums1.empty() || nums2.empty() || k <= 0) return result;
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> heap(comp);
        
        heap.emplace(0,0);
        while (k-- && !heap.empty()) {
            auto p = heap.top(); heap.pop();
            result.emplace_back(nums1[p.first], nums2[p.second]);
            if (p.first+1 < nums1.size())
                heap.emplace(p.first+1, p.second);
            
            // both (i,j) and (i-1,j+1) can generate (i,j+1), so we just choose x or y to add, 
            // when i = 0, there is no j+1
            if (p.first == 0 && p.second+1 < nums2.size())
                heap.emplace(p.first, p.second+1);
        }
        return result;
    }
};
