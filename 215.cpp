/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    
    // heap
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> pq;
    //     for (int num : nums) {
    //         pq.push(-num);
    //         if (pq.size() > k) pq.pop();
    //     }
    //     return -pq.top();
    // }
    
    // qsort method
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, k, 0, (int)nums.size()-1);
    }
    
    int find(vector<int>& nums, int k, int l, int r) {
        int x = nums[l], i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] > x) j--;
            while (i < j && nums[i] <= x) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        nums[l] = nums[i];
        nums[i] = x;        
        
        // cout << i << " " << nums[i] << endl;
        if (r-i+1 == k) return nums[i];
        else if (r-i+1 > k) return find(nums, k, i+1, r);
        else return find(nums, k-(r-i+1), l, i-1);
    }
};
