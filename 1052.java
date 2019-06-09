/*
Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 

Note:

1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
*/

class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int n = customers.length;
        int[] customSum = new int[n];
        int[] statifiedSum = new int[n];
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s1 += customers[i];
            s2 += grumpy[i] == 1 ? 0 : customers[i];
            customSum[i] = s1;
            statifiedSum[i] = s2;
        }
        
        int res = 0;
        // i is the start index of technique, so sum(0, i-1) + statifiedSum(i, i+X-1) + sum(i+x, n-1)
        for (int i = 0; i + X <= n; i++) {
            int val = 0;
            val += i-1 < 0 ? 0 : statifiedSum[i-1];
            val += customSum[i+X-1] - (i-1 < 0 ? 0 : customSum[i-1]);
            val += i+X >= n ? 0 : statifiedSum[n-1] - statifiedSum[i+X-1];
            res = Math.max(res, val);
        }
        return res;
     }
}
