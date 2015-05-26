class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0;i < nums.size();i++)
            s.insert(nums[i]);
        
        multiset<int>::iterator it = s.begin();
        for(int i = 0;i < nums.size()-k;i++)
            it++;
        return *it;   
    }
};
