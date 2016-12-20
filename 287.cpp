class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (r-l)/2+l;
            int cnt1 = 0, cnt2 = 0, total = 0;
            for (int num : nums) {
                if (num < l || num > r) continue;
                total++;
                if (num < mid) cnt1++;
                else if (num > mid) cnt2++;
            }
            
            if (total-cnt1-cnt2 > 1) return mid;
            if (cnt1 > cnt2 || (((total-1)&1)==0 && cnt1==cnt2)) r = mid-1;
            else l = mid+1;
            // cout << mid << " " << cnt1 << " " << cnt2 << " " << total << endl;
        }
        return -1;
    }
};
