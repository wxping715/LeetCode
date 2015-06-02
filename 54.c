int get_cell(int** grid,int i,int j){
    return *(*(grid+i)+j);
}
 
 
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    
    int** grid = matrix;
    int m = matrixRowSize, n = matrixColSize;
    
    if(n == 0 || m == 0) return NULL;
    
    int* res = (int *)malloc(n*m*sizeof(int));

    int x[4] = {0, 0, m-1, m-1};
    int y[4] = {0, n-1, n-1, 0};
    int ax[4] = {1, 1, -1, -1};
    int ay[4] = {1, -1, -1, 1};
        
    int cnt = 0, rlen = m, clen = n, it;
    while(rlen > 0 && clen > 0){
        
        if(rlen == 1){
            it = 0;
            while(it < clen){
                res[cnt++] = get_cell(grid,x[0],y[0]+it);
                it++;
            }
            break;
        }else if(clen == 1){
             it = 0;
             while(it < rlen){
                res[cnt++] = get_cell(grid,x[0]+it,y[0]);
                it++;
             }
             break;
        }
        
        it = 0;
        while(it < clen-1){
            res[cnt++] = get_cell(grid,x[0],y[0]+it);
            it++;
        }
        it = 0;
        while(it < rlen-1){
            res[cnt++] = get_cell(grid,x[1]+it,y[1]);
            it++;
        }
        it = 0;
        while(it < clen-1){
            res[cnt++] = get_cell(grid,x[2],y[2]-it);
            it++;
        }
        it = 0;
        while(it < rlen-1){
            res[cnt++] = get_cell(grid,x[3]-it,y[3]);
            it++;
        }
        
        for(int i = 0;i < 4;i++){
            x[i] += ax[i];
            y[i] += ay[i];
        }
        clen -= 2; rlen -= 2;
    }
    
    return res;
}
