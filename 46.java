class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<>();
        for (int num : nums) path.add(num);
        
        generate(result, path, nums.length, 0);
        return result;
    }
    
    private void generate(
        List<List<Integer>> result,
        List<Integer> path,
        int n,
        int start
    ) {
        if (start == n) {
            result.add(new ArrayList<Integer>(path));
            return;
        }
        
        for (int i = start; i < n; i++) {
            swap(path, start, i);
            generate(result, path, n, start+1);
            swap(path, start, i);
        }
    }
    
    private void swap(List<Integer> list, int l, int r) {
        int t = list.get(l);
        list.set(l, list.get(r));
        list.set(r, t);
    }
}
