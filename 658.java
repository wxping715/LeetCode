class Solution {
    
    // log(n) + k
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int l = 0, r = arr.length-1;
        while (l < r) {
            if (l+1 == r) {
                l = Math.abs(arr[l]-x) > Math.abs(arr[r]-x) ? r : l;
                break;
            }
            int m = (l + r) / 2;
            if (arr[m] < x) l = m;
            else r = m;
        }
        
        int i = l, j = l;
        Deque<Integer> deque = new ArrayDeque<Integer>();
        deque.offerFirst(arr[l]);
        while ((--k) > 0) {
            if (i <= 0) deque.offerLast(arr[++j]);
            else if (j+1 >= arr.length) deque.offerFirst(arr[--i]);
            else {
                if (Math.abs(arr[i-1] - x) <= Math.abs(arr[j+1] - x))
                    deque.offerFirst(arr[--i]);
                else deque.offerLast(arr[++j]);
            }
        }
        return new ArrayList<Integer>(deque);
    }
}
