int removeElement(int A[], int n, int elem) {
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(A[i] != elem)
            A[cnt++] = A[i];
    }
    return cnt;
}