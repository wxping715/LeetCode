class Solution {
    public int maxDistToClosest(int[] seats) {
        int slots = 0, res = 0;
        boolean hasLeft = false;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 0) slots++;
            else {
                if (hasLeft) res = Math.max(res, slots/2 + slots%2);
                else res = Math.max(res, slots);
                hasLeft = true;
                slots = 0;
            }
        }
        // must have left
        if (slots > 0) res = Math.max(res, slots);
        return res;
    }
}
