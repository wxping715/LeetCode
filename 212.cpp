class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode() {
        memset(next, 0, sizeof(next));
        isWord = false;
    }
};

class Solution {
public:

    // build trie using all the words, and start to search from i,j. 
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        TrieNode* root = buildTrie(words);
        string cur = "";
        
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m , vector<bool>(n, false));
                search(board, res, visited, root, cur, i, j);
            }
        return vector<string>(res.begin(), res.end());
    }
    
    void search(vector<vector<char>>& board, unordered_set<string>&res, vector<vector<bool>>& visited, TrieNode* p, string& cur, int x, int y) {
        char ch = board[x][y];
        int m = board.size(), n = board[0].size();
        
        if (!p->next[ch-'a']) return;
        
        visited[x][y] = true;
        cur.push_back(board[x][y]);
        // cout << x << " " << y << " " << cur << endl;
        
        p = p->next[ch-'a'];
        if (p->isWord) res.insert(cur);
        int ax[4] = {-1, 0, 1, 0};
        int ay[4] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nx = ax[i]+x, ny = ay[i]+y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                continue;
            search(board, res, visited, p, cur, nx, ny);
        }
        cur.pop_back();
        visited[x][y] = false;
    }
    
    TrieNode *buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (string word : words) {
            TrieNode* p = root;
            for (char ch : word) {
                if (!p->next[ch-'a']) 
                    p->next[ch-'a'] = new TrieNode();
                p = p->next[ch-'a'];
            }
            p->isWord = true;
        }
        return root;
    }
};
