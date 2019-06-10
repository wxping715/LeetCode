class Solution {
    public int maxChunksToSorted(int[] arr) {
        // for each chunk i, maxi is the largest number in it.
        // maxi+1 == (number of elements <= maxi) + offset
        int res = 0, count = 0, max = 0, offset = 0;
        for (int x : arr) {
            max = Math.max(x, max);
            count++;
            if (offset + count == max + 1) {
                res++;
                offset += count;
                count = 0;
            }
        }
        return res;
    }
}
