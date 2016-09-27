class Solution {
public:

    /*
    * Be careful: num * digits may overlimit
    */
    int findNthDigit(int n) {
        int num = 9, digits = 1;
        while (n > (long long)num*digits) {
            n -= (long long)num*digits;
            // cout << num*digits << endl;
            num *= 10;
            digits += 1;
        }
        
        int remain = n % digits;
        int res = n / digits;
        
        // cout << res << " " << remain << " " << digits << endl;
        num /= 9;
        if (remain == 0) {
            num += res - 1;
            return num%10;
        } else {
            num += res;
            int loop = digits - remain;
            while (loop--) {
                num /= 10;
            }
            return num%10;
        }
    }
};
