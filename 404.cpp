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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, int& sum) {
        if (!root || (!root->left && !root->right)) return;
        if (root->left && (!root->left->left && !root->left->right)) {
            sum += root->left->val;
        }
        
        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);
    }
};

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (!root) return 0;
        queue<pair<TreeNode*, bool>> q;
        q.emplace(root, false);
        while (!q.empty()) {
            int n = q.size();
            auto p = q.front();
            TreeNode* cur = p.first;
            q.pop();
            
            if (!cur->left && !cur->right && p.second) sum += cur->val;
            if (cur->left) q.emplace(cur->left, true);
            if (cur->right) q.emplace(cur->right, false);
        }
        return sum;
    }
};
