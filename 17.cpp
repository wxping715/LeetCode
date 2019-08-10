class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return Collections.emptyList();
        
        List<String> map = new ArrayList<>(Arrays.asList(
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        ));
        
        Queue<String> queue = new LinkedList<>();
        queue.offer("");
        for (int i = 0; i < digits.length(); i++) {
            int d = digits.charAt(i) - '0';
            char[] chars = map.get(d).toCharArray();
            int n = queue.size();
            while (n-- > 0) {
                String poll = queue.poll();
                for (char ch : chars) {
                    queue.offer(poll + ch);
                }
            }
        }
        return new ArrayList<>(queue);
    }
}
