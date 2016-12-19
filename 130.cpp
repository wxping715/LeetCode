class Solution {
    public:
        typedef vector<vector<char> > BOARDTYPE;

        void solve(BOARDTYPE &board) {
            if (board.empty() || board[0].empty()) return;
            int N = board.size(), M = board[0].size();
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                    if (i == 0 || j == 0 || i == N-1 || j == M-1)
                        dfs(board, i, j); // you may call dfs or bfs here!
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                    board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
        }

         void dfs(BOARDTYPE &board, int row, int col) {
            int N = board.size(), M = board[0].size();
            if (row < 0 || row >= N || col < 0 || col >= M) return;
            if (board[row][col] != 'O') return;
            stack<pair<int,int>> s;
            s.push(make_pair(row,col));
            board[row][col] = 'V';//把不需要更改的‘O’设为‘V’.
            while(!s.empty()){
                row = s.top().first;
                col = s.top().second;
                s.pop();
                if(row+1<N && board[row+1][col]=='O'){
                    s.push(make_pair(row+1,col));
                    board[row+1][col]='V';
                }
                if(row-1>=0 && board[row-1][col]=='O'){
                    s.push(make_pair(row-1,col));
                    board[row-1][col]='V';
                }
                if(col+1<M && board[row][col+1]=='O'){
                    s.push(make_pair(row,col+1));
                    board[row][col+1]='V';
                }
                if(col-1<N && board[row][col-1]=='O'){
                    s.push(make_pair(row,col-1));
                    board[row][col-1]='V';
                }
            }//end while
        }
    };
