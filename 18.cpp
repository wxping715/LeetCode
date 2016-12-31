class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i+3 < nums.size(); i++) {
            while (i > 0 && i+3 < nums.size() && nums[i] == nums[i-1]) i++;
            vector<vector<int>> cres = threeSum(nums, i+1, target-nums[i]);
            // cout << nums[i] << " " << target-nums[i] << " " << cres.size() << endl;
            for (auto trip : cres) {
                trip.insert(trip.begin(), nums[i]);
                res.push_back(trip);
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>&nums, int idx, int target) {
        vector<vector<int>> res;
        int p1, p2, p3;
        for (p1 = idx; p1+2 < nums.size(); p1++) {
            while (p1 > idx && p1+2 < nums.size() && nums[p1] == nums[p1-1]) p1++;
            
            p2 = p1+1, p3 = nums.size()-1;
            while (p2 < p3) {
                if (nums[p1]+nums[p2]+nums[p3]==target) {
                    vector<int> cres;
                    cres.push_back(nums[p1]);
                    cres.push_back(nums[p2]);
                    cres.push_back(nums[p3]);
                    res.push_back(cres);
                    p2++; p3--;
                    while (p2 < p3 && nums[p2] == nums[p2-1]) p2++;
                    while (p2 < p3 && nums[p3] == nums[p3+1]) p3--;
                }
                else if (nums[p1]+nums[p2]+nums[p3]<target) p2++;
                else p3--;
            }
        }
        return res;
    }
};
