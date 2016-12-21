/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Show Company Tags
Hide Tags
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << endl;
            if (i > k) s.erase(nums[i-k-1]);
            auto pos = s.lower_bound(nums[i]-t);
            cout << *pos << endl;
            if (pos != s.end() && *pos-nums[i] <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
