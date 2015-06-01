/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void set_cell(int** grid,int i,int j,int val){
    *(*(grid+i)+j) = val;
}
 
int** generateMatrix(int n) {
    
    if(n == 0) return NULL;
    
    int** grid = (int**)malloc(n*sizeof(int*));
    for(int i = 0;i < n;i++){
        int* r = (int *)malloc(n*sizeof(int));
        grid[i] = r;
    }

    int x[4] = {0, 0, n-1, n-1};
    int y[4] = {0, n-1, n-1, 0};
    int ax[4] = {1, 1, -1, -1};
    int ay[4] = {1, -1, -1, 1};
        
    int cnt = 0, len = n, it;
    while(len > 0){
        
        if(len == 1){
            set_cell(grid,x[0],y[0],++cnt);
            break;
        }
        
        it = 0;
        while(it < len-1){
            set_cell(grid,x[0],y[0]+it,++cnt);
            it++;
        }
        it = 0;
        while(it < len-1){
            set_cell(grid,x[1]+it,y[1],++cnt);
            it++;
        }
        it = 0;
        while(it < len-1){
            set_cell(grid,x[2],y[2]-it,++cnt);
            it++;
        }
        it = 0;
        while(it < len-1){
            set_cell(grid,x[3]-it,y[3],++cnt);
            it++;
        }
        
        for(int i = 0;i < 4;i++){
            x[i] += ax[i];
            y[i] += ay[i];
        }
        len -= 2;
    }  
    
    return grid;
}
