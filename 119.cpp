/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) result[j] = result[j-1];
                else if (j != 0)
                    result[j] = result[j-1] + result[j];
            }
        }
        return result;
    }
};
