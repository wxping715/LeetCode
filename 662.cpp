/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // O(N)
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            int n = q.size(), l = INT_MIN, r;
            while (n--) {
                auto cur = q.front();
                q.pop();
                
                if (l == INT_MIN) l = cur.second;
                r = cur.second;
                
                if (cur.first->left) q.emplace(cur.first->left, cur.second*2-1);
                if (cur.first->right) q.emplace(cur.first->right, cur.second*2);
            }
            maxWidth = max(maxWidth, r-l+1);
        }
        return maxWidth;
    }
};
