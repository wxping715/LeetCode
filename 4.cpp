class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n)&1) return KthNumber(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1);
        
        return (1.0*KthNumber(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2) + 
            KthNumber(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1))/2; 
    }
    
    int KthNumber(vector<int> &nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        int m = r1-l1+1, n = r2-l2+1;
        
        // assume m is always smaller than n
        if (m > n) return KthNumber(nums2, nums1, l2, r2, l1, r1, k);
        if (m == 0) return nums2[l2+k-1];
        if (k == 1) return min(nums1[l1], nums2[l2]);
        
        int m1 = min(k/2, m), m2 = k - m1;
        
        if (nums1[m1+l1-1] < nums2[m2+l2-1]) return KthNumber(nums1, nums2, l1+m1, r1, l2, r2, k-m1);
        else if (nums1[m1+l1-1] > nums2[m2+l2-1]) return KthNumber(nums1, nums2, l1, r1, l2+m2, r2, k-m2);
        else return nums1[m1+l1-1];
    }
};
