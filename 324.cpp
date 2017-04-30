class Solution {
public:
    
    // NlogN
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), j = (n-1)/2, k = n-1;
        for (int i = 0; i < n; i++) {
            nums[i] = i & 1 ? tmp[k--] : tmp[j--];
        }
    }
    
    /*void wiggleSort(vector<int>& nums) {
        int idx = kthelem(nums, 0, nums.size()-1, nums.size()/2);
        //pass
        int median = nums[idx];
        int n = nums.size();
        #define m(i) (1+2*i)%(n|1)
        
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (nums[m(j)] > median) swap(nums[m(i++)], nums[m(j++)]);
            else if (nums[m(j)] < median) swap(nums[m(i)], nums[m(k--)]);
            else j++;
        }
    }
    
    int kthelem(vector<int> &nums, int l, int r, int k) {
        if (l > r) return -1;
        int i = l, j = r, x = nums[i];
        
        while (i < j) {
            while (i < j && nums[j] >= x) j--;
            if (j > i) nums[i++] = nums[j];
            
            while (i < j && nums[i] < x) i++;
            if (j > i) nums[j--] = nums[i];
        }
        nums[i] = x;
        
        // cout << i << " " << nums[i] << " " << k << endl;
        if ((i-l+1) == k) return i;
        else if ((i-l+1) < k) return kthelem(nums, i+1, r, k-(i-l+1));
        else return kthelem(nums, l, i-1, k);
    }*/
};
