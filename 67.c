char *addBinary(char *a, char *b) {
    int len1 = strlen(a), len2 = strlen(b);
    
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    char *ans = (char *)malloc(len*sizeof(char));
    
    int k = 0,i,j;
    for(i = len1 - 1,j = len2 - 1; i >= 0 && j >= 0;i--,j--){
        *(ans+k) = *(a+i) + *(b+j) - '0';
        k++;
    }
    while(i >= 0){
        *(ans+k) = *(a+i);
        k++;i--;
    } 
    while(j >= 0){
        *(ans+k) = *(b+j);
        k++;j--;
    }
    
    int add = 0;
    for(int i = 0;i < k;i++){

        *(ans+i) += add;
        if(*(ans+i) > '1'){
            *(ans+i) -= 2;
            add = 1;
        }
        else add = 0;
    }
    if(add > 0) {
        *(ans+k) = '1';
        k++;
    }
    *(ans+k) = '\0';

    int tmp;
    for(int i = 0;i < k/2;i++){
        tmp = *(ans + i);
        *(ans + i) = *(ans + k - 1 - i);
        *(ans + k - 1 - i) = tmp;
    }
    return ans;
}