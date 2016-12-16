// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (r-l)/2 + l;
            bool res = isBadVersion(mid);
            if (!res) l = mid+1;
            else if (mid==1 || !isBadVersion(mid-1)) return mid;
            else r = mid-1;
        }
        return -1;
    }
};
