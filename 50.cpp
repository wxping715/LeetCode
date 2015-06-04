class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        bool flag = true;
        if(n < 0){
            flag = false;
            n = -n;
        }
        
        while(n){
            if(n%2==1){
                ans *= x;
                n--;
            }else{
                x *= x;
                n /= 2;
            }
        }
        
        if(flag)  return ans;
        return 1.0/ans;
    }
};
