class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        k = k < 0 ? -k : k;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int runningSum = 0;
        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            if (k != 0) runningSum = runningSum % k;
            Integer prev = map.get(runningSum);
            if (prev != null) {
                if (i - prev > 1) return true;
            } else map.put(runningSum, i);
        }
        return false;
    }
}
