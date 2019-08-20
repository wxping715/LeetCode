class Solution {
    /*
    * suppose a1, a2, a3, a4
    * expect ai < a(i+1)
    * but ai > a(i+1) swap them a(i+1) < ai, then a(i-1) < a(i+1)
    * same with other cases
    */
    public void wiggleSort(int[] nums) {
        boolean less = true;
        for (int i = 0; i+1 < nums.length; i++) {
            if ((less && nums[i] > nums[i+1]) ||
               (!less && nums[i] < nums[i+1]))
                swap(nums, i, i+1);
            less = !less;
        }
    }
    
    private void swap(int[] nums, int l, int r) {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
}
