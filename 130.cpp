/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == 0 || j == 0 || i == n-1 || j == m-1)
                    bfs(board, i, j);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
    }
    
    void bfs(vector<vector<char>>& board, int x, int y) {
        int ax[4] = {0, -1, 0, 1};
        int ay[4] = {-1, 0, 1, 0};
        int n = board.size(), m = board[0].size();
        
        if (board[x][y] != 'O') return;
        board[x][y] = 'T';
        
        queue<pair<int,int>> q;
        q.emplace(x, y);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            
            
            for (int i = 0; i < 4; i++) {
                int r = x + ax[i], c = y + ay[i];
                if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O')
                    continue;
                board[r][c] = 'T';
                q.emplace(r, c);
            }
        }
    }
};
