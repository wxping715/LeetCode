int removeDuplicates(int A[], int n) {
    int cnt = 0,pre = 0x3f3f3f3f;
    for(int i = 0;i < n;i++){
        if(A[i] != pre){
            A[cnt++] = A[i];
            pre = A[i];
        }
    }
    return cnt;
}