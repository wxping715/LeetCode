/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

special test cases:
1993
98368
*/

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits, idxs;
        int mi = -1, i = 0;
        while (num) {
            int d = num%10;
            digits.push_back(d);
            // update idxs
            if (mi != -1 && digits[mi] > d)
                idxs.push_back(mi);
            else {
                if (mi == -1 || digits[mi] < d)
                    mi = i;
                idxs.push_back(-1);
            }
            i++;
            num /= 10;
        }
        
        for (int i = digits.size()-1; i >= 0; i--) {
            if (idxs[i] != -1) {
                swap(digits[i], digits[idxs[i]]);
                break;
            }
        }
        
        int r = 0;
        for (int i = digits.size()-1; i >= 0; i--)
            r = r * 10 + digits[i];
        return r;
    }
};
