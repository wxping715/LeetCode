
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize <= 1) return;
    
    int n = matrixRowSize;
    int x[4] = {0,0,n-1,n-1};
    int y[4] = {0,n-1,n-1,0};
    int ax[4] = {1,1,-1,-1};
    int ay[4] = {1,-1,-1,1};
     
    int times = 0,len = n - 1;
    while(times < n/2){
        
        for(int i = 0;i < len;i++){
            int t = *(*(matrix+x[1]+i)+y[1]);
            *(*(matrix+x[1]+i)+y[1]) = *(*(matrix+x[0])+y[0]+i);
            *(*(matrix+x[0])+y[0]+i) = *(*(matrix+x[3]-i)+y[3]);
            *(*(matrix+x[3]-i)+y[3]) = *(*(matrix+x[2])+y[2]-i);
            *(*(matrix+x[2])+y[2]-i) = t;
        }
        
        for(int i = 0;i < 4;i++) x[i] += ax[i];
        for(int i = 0;i < 4;i++) y[i] += ay[i];
        times++;
        len -= 2;
    }
}
