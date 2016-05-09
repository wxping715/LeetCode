
/*
* 1. using (num-1)%3 to determine the number of zeros.
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        return ((num-1)&num)==0 && (num-1)%3==0;
    }
};
