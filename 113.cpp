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

    // dfs
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        find(root, res, path, 0, sum);
        return res;
    }
    
    void find(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int sum, int target) {
        if (!root) return;
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == target)
            res.push_back(path);
        if (root->left) find(root->left, res, path, sum, target);
        if (root->right) find(root->right, res, path, sum, target);
        path.pop_back();
    }
    
    // iteratively
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> st;
        TreeNode* cur = root, *pre = NULL;
        int csum = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push_back(cur);
                csum += cur->val;
                cur = cur->left;
            }
            cur = st.back();
            if (!cur->left && !cur->right && csum == sum) {
                vector<int> path;
                for (auto node : st)
                    path.push_back(node->val);
                res.push_back(path);
            }
            if (cur->right && cur->right != pre)
                cur = cur->right;
            else {
                pre = cur;
                csum -= cur->val;
                st.pop_back();
                cur = NULL;
            }
        }
        return res;
    }
};
