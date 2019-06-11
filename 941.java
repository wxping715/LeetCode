class Solution {
    public boolean validMountainArray(int[] A) {
        if (A.length <= 2) return false;
        
        int peak = 0;
        while (peak+1 < A.length && A[peak] < A[peak+1]) peak += 1;
        if (peak == 0 || peak + 1 == A.length) return false;
        while (peak+1 < A.length && A[peak] > A[peak+1]) peak += 1;
        return peak + 1 == A.length;
    }
}
