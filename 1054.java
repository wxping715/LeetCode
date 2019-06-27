/*
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]

*/

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int barcode : barcodes)
            map.put(barcode, map.getOrDefault(barcode, 0) + 1);
        List<Map.Entry<Integer, Integer>> list = new ArrayList(map.entrySet());
        Collections.sort(list, (a, b) -> Integer.compare(b.getValue(), a.getValue()));
        
        int[] ans = new int[barcodes.length];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : list) {
            int cnt = entry.getValue();
            while ((cnt--) > 0) {
                ans[i] = entry.getKey();
                i += 2;
                if (i >= barcodes.length) i = 1;
            }
        }
        return ans;
    }
}
