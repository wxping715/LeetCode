class Solution {
public:

    //two pass
    // void sortColors(vector<int>& nums) {
    //     int cnt[3] = {0};
    //     for (int num : nums)
    //         cnt[num]++;
    //     int k = 0;
    //     for (int i = 0;i < 3; i++) {
    //         while (cnt[i]--)
    //             nums[k++] = i;
    //     }
    // }
    
    //one pass
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size()-1;
        for (int i = 0; i <= two; i++) {
            while (nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while (nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};
