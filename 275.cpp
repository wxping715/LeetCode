class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1, len = citations.size(), mid = 0;
        while (l <= r) {
            mid = (r-l)/2+l;
            if (citations[mid] == len-mid) return citations[mid];
            else if (citations[mid] < len-mid) l = mid + 1;
            else r = mid - 1;
        }
        return len-r-1;
    }
};
