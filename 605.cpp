/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*/

class Solution {
public:
    
    // solution1: find the left and right boundary
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = -1, r = -1;
        for (int i = 0; i < flowerbed.size(); i++) {
            // set left
            if (flowerbed[i] == 0)
                if (l == -1) l = i;
            
            // set right
            if (flowerbed[i] == 1)
                r = i-1;
            else if (i+1 == flowerbed.size())
                r = i;
            
            if (l != -1 && r != -1) {
                int k = r-l+1;
                if (l > 0 && r+1 < flowerbed.size())
                    k -= 2;
                else if (l > 0 || r+1 < flowerbed.size())
                    k -= 1;
                
                cout << l << " " << r << " " << k << endl;
                if (k > 0) n -= (k+1)/2;
                l = -1; r = -1;
            }
        }
        return n <= 0;
    }
    
    // solution2: plant flowers greedily
};
