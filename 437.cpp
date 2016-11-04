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
    int pathSum(TreeNode* root, int sum) {
        vector<int> s;
        s.push_back(0);
        
        int res = 0;
        dfs(root, sum, s, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<int> s, int& res) {
        if (root == NULL) return;
        
        if (s.empty())  s.push_back(root->val);
        else s.push_back(s.back()+root->val);
        
        for (int i = 0; i < s.size()-1; i++) {
            // cout << s[i] <<  " " << s.back*
            if (s.back() - s[i] == sum) res++;
        }
        if (root->left != NULL)
            dfs(root->left, sum, s, res);
        if (root->right != NULL)
            dfs(root->right, sum, s, res);
        s.pop_back();
    }
};
