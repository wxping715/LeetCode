class Solution {
public:
    
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
        // vector<bool> res(n+1, false);
        // res[1] = true;
        // res[2] = true;
        // res[3] = true;
        // for (int i = 4; i <= n; i++) {
        //     for (int j = 1; j <= 3; j++) {
        //         if (!res[i-j]) {
        //             res[i] = true;
        //             break;
        //         }
        //     }
            
        // }
        // return res[n];
    }
};
