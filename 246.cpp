/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> hash{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        int i = 0, j = num.length()-1;
        while (i <= j) {
            // cout << hash[num[i]] << " " << num[j] << endl;
            if (hash[num[i]] != num[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
