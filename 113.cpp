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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<TreeNode* > path;
        int psum = 0;
        
        if (root == NULL) return res;
        dfs(root, res, path, psum, sum);
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<TreeNode *> &path, int& psum, int sum) {
        path.push_back(root);
        psum += root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (psum == sum) {
                vector<int> one;
                for (int i = 0;i < path.size(); i++) one.push_back(path[i]->val);
                res.push_back(one);
            }
            path.pop_back();
            psum -= root->val;
            return;
        }
    
        if (root->left != NULL) dfs(root->left, res, path, psum, sum);
        if (root->right != NULL) dfs(root->right, res, path, psum, sum);
        path.pop_back();
        psum -= root->val;
    }
};
