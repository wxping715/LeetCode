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

    // bool hasPathSum(TreeNode* root, int sum) {
    //     // return dfs(root, 0, sum);
    //     return bfs(root, sum);
    // }
    
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
    
    bool dfs(TreeNode* root, int sum, int target) {
        if (!root) return false;
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == target) return true;
            return false;
        }
        
        if (root->left && dfs(root->left, sum, target)) return true;
        if (root->right && dfs(root->right, sum, target)) return true;

        sum -= root->val;
        return false;
    }
    
    bool bfs(TreeNode* root, int sum) {
        queue<pair<TreeNode*, int>> q;
        if (!root) return false;
        q.emplace(root, root->val);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            TreeNode* cnode = cur.first;
            int csum = cur.second;
            
            if (!cnode->left && !cnode->right && csum == sum) return true;
            
            if (cnode->left) q.emplace(cnode->left, csum+cnode->left->val);
            if (cnode->right) q.emplace(cnode->right, csum+cnode->right->val);
        }
        return false;
    }
};
