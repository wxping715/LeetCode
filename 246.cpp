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
