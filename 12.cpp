class Solution {
public:
    string intToRoman(int num) {
        string romanStr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string res;
        if (num < 1 || num > 3999) return res;
        int idx = 0;
        while (num) {
            while (idx < 13 && number[idx] > num)
                idx++;
            
            int r = num/number[idx];
            while (r--)
                res += romanStr[idx];
            num %= number[idx];
        }
        return res;
    }
};
