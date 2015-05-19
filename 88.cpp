class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1,k = m + n - 1;
        while(j >= 0)
        {
            A[k--] = (i < 0 || A[i] < B[j])? B[j--] : A[i--];
        }
    }
};