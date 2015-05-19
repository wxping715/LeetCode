class Solution {
public:
    void sortColors(int A[], int n) {
        int r = 0, w = 0, b = 0;
        for(int i = 0;i < n;i++){
            if(A[i] == 0) r++;
            else if(A[i] == 1) w++;
            else b++;
        }
        int i = 0;
        while(r--) A[i++] = 0;
        while(w--) A[i++] = 1;
        while(b--) A[i++] = 2;
    }
};