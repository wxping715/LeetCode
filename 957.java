class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        Map<Integer, Integer> hashmap = new HashMap<>();
        List<int[]> cellsStatus = new ArrayList<>();
        hashmap.put(toInteger(cells), 0);
        cellsStatus.add(cells);
        int steps = 0;
        
        int[] curr = cells;
        int first = 0;
        while (true) {
            int[] next = next(curr);
            steps++;
            if (steps == N) return next;
            
            int v = toInteger(next);
            if (hashmap.containsKey(v)) {
                first = hashmap.get(v);
                break;
            }
            hashmap.put(v, steps);
            cellsStatus.add(next);
            curr = next;
        }
        int cycleLength = steps - first;
        if (cycleLength == 0) return cellsStatus.get(cellsStatus.size()-1);
        
        N -= steps;
        return cellsStatus.get((N % cycleLength) + first);
    }
    
    private int toInteger(int[] cells) {
        int ans = 0;
        for (int bit : cells)
            ans = ans*2 + bit;
        return ans;
    }
    
    private int[] next(int[] cells) {
        int[] next = new int[cells.length];
        for (int i = 0; i < cells.length; i++)
            next[i] = (i-1 >= 0 && i+1 < cells.length && cells[i-1] == cells[i+1]) ? 1 : 0;
        return next;
    }
}
