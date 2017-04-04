class Solution {
public:

    int countArrangement(int N) {
        vector<bool> visited(N+1, false);
        int res = 0;
        search(visited, N, N, res);
        return res;
    }
    
    void search(vector<bool>& visited, int N, int idx, int& cnt) {
        for (int k = 1; k <= N; k++) {
            if (!visited[k] && ((k%idx == 0)||(idx%k == 0))) {
                if (idx == 1) {
                    cnt++;
                    return;
                } else {
                    visited[k] = true;
                    search(visited, N, idx-1, cnt);
                    visited[k] = false;
                }
                   
            }
        }
    }
};
