class Solution {
    int ans = 0;
    public int pathSum(int[] nums) {
        ans = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            // num/10 is the id, num%10 is the value
            map.put(num/10, num%10);
        }
        dfs(nums[0]/10, 0, map);
        return ans;
    }
    
    private void dfs(int id, int sum, Map<Integer, Integer> tree) {
        if (!tree.containsKey(id)) return;
        sum += tree.get(id);
        
        int depth = id / 10, pos = id % 10;
        int left = (depth + 1) * 10 + 2 * pos - 1;
        int right = left + 1;
        
        if (!tree.containsKey(left) && !tree.containsKey(right)) {
            ans += sum;
        } else {
            dfs(left, sum, tree);
            dfs(right, sum, tree);
        }
    }
}
