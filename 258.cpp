class Solution {
public:
    
    // a*1000 + b*100 + c*10 + d = (a+b+c+d) + (a*999 + b*99 + c*9)
    // the right part is always be moded by 9
    int addDigits(int num) {
        int r = num%9;
        return r ? r : 9;
    }
};
