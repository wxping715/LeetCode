class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) return false;
        
        int sum = 0;
        for (int i = 1; i*i < num; i++) {
            if (num % i == 0) {
                if (i == 1) sum += i;
                else sum += i + num/i;
            }
        }
        return (sum == num);
    }
};
