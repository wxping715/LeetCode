class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int ret = 0;
        vector<int> id(m*n, -1), res;
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
        for (auto p : positions) {
            ret++;
            int cid = p.first*n + p.second;
            id[cid] = cid;
            for (int i = 0; i < 4; i++) {
                int nx = p.first+ax[i];
                int ny = p.second+ay[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                
                int nidx = find(id, nx*n+ny);
                if (nidx != -1 && nidx != cid) {
                    ret--;
                    uunion(id, nidx, cid);
                }
            }
            res.push_back(ret);
        }
        return res;
    }
    
    void uunion(vector<int>& id, int x, int y) {
        int xid = find(id, x), yid = find(id, y);
        id[xid] = yid;
    }
    
    int find(vector<int>& id, int x) {
        if (id[x] == -1 || id[x] == x)
            return id[x];
        int xid = find(id, id[x]);
        id[x] = xid;
        return xid;
    }
};
