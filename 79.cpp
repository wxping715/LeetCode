class Solution {
public:
    
    int ax[4] = {-1, 0, 1, 0}, ay[4] = {0, 1, 0, -1};
    int m,n;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0 || board.size() == 0 || board[0].size() == 0) return false;
        
        m = board.size(), n = board[0].size();
        bool visited[m*n];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if (board[i][j] != word[0])
                    continue;
                visited[i*n+j] = true;
                if(search(i,j,board,word,0,visited))
                    return true;
                visited[i*n+j] = false;
            }
        return false;
    }
    
    bool search(int x, int y, vector<vector<char>>& board, string word, int k, bool *visited) {
        // cout << x << " " << y << endl;
        // cout << word[k] << endl;
        int n = board[0].size();
        
        if (board[x][y] != word[k]) return false;
        if (k == word.size()-1) return true;
        for (int i = 0;i < 4;i++) {
            int tx = x + ax[i];
            int ty = y + ay[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx*n+ty]) continue;
            
            visited[tx*n+ty] = true;
            if(search(tx, ty, board, word, k+1, visited)) return true;
            visited[tx*n+ty] = false;
        }
        return false;
    }
};
