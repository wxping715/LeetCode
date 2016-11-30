class Solution {
public:
    int lastRemaining(int n) {
        return dfs(n, true);
    }
    
    int dfs(int n, bool left) {
        if (n == 1) return 1;
        
        if (n%2==0 && !left) return 2*dfs(n/2, !left)-1;
        else return 2*dfs(n/2, !left);
    }
};
