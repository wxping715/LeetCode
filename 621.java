class Solution {
    public int leastInterval(char[] tasks, int n) {
        int sum = 0, maxCount = 0;
        int[] hashset = new int[26];
        for (char ch : tasks) {
            hashset[ch-'A'] += 1;
            maxCount = Math.max(hashset[ch-'A'], maxCount);
            sum++;
        }
        
        int cycle = sum/(n+1) + (sum%(n+1) == 0 ? 0 : 1);
        if (cycle > maxCount) return sum;
        int count = 0;
        for (int i = 0; i < 26; i++)
            if (hashset[i] == maxCount)
                count++;
        return (maxCount-1)*(n+1) + count;
    }
}
