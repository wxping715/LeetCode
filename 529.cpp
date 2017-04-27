class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') board[x][y] = 'X';
        else if (board[x][y] == 'E') revealEmpty(board, x, y);
        
        return board;
    }
    
    void revealEmpty(vector<vector<char>>& board, int x, int y) {
        // cout << x << " " << y << " haha" << endl;
        int m = board.size(), n = board[0].size();
        int mines = 0;
        for (int i = x-1; i <= x+1; i++)
            for (int j = y-1; j <= y+1; j++) {
                if (i < 0 || i >= m || j < 0 || j >= n) continue;
                if (i == x && j == y) continue;
                
                // cout << i << " " << j << endl;
                if (board[i][j] == 'M' || board[i][j] == 'X') 
                    mines++;
            }
        
        if (mines > 0) board[x][y] = mines + '0';
        else {
            board[x][y] = 'B';
            for (int i = x-1; i <= x+1; i++)
                for (int j = y-1; j <= y+1; j++) {
                    if (i < 0 || i >= m || j < 0 || j >= n) continue;
                    if (i == x && j == y) continue;
                    
                    if (board[i][j] == 'E')
                        revealEmpty(board, i, j);
                }
        }
    }
};
