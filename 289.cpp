class Solution {
public:
    /*
    * using an integer to store two status, the last bit to store the old status, and previous to store now status
    */
    void gameOfLife(vector<vector<int>>& board) {
        int ax[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int ay[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        m = board.size(), n = board[0].size();
        int ns, s, live, dead, tmp;
        
        for (int i = 0;i < m; i++) 
            for (int j = 0;j < n;j++) {
                live = dead = 0;
                for (int k = 0;k < 8;k++) {
                    tmp = get_val(i+ax[k], j+ay[k], board);
                    if (tmp < 0) continue;
                    
                    tmp &= 1;
                    if (tmp == 1) live++;
                    else if (tmp == 0) dead++;
                }
                ns = s = get_val(i,j,board);
                if (s == 1 && (live < 2 || live > 3)) ns = 0;
                else if (s == 1) ns = 1;
                else if (s == 0 && live == 3) ns = 1;
                
                board[i][j] = (ns<<1) + s;
            }
            
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n; j++)
                board[i][j] = (board[i][j] & 2) >> 1;
    }
    
    int get_val(int x, int y, vector<vector<int>>& boa) {
        if (x < 0 || x >= m || y < 0 || y >= n) return -1;
        return boa[x][y];
    }
    
private:
    int m, n;
};
