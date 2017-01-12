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
        int res = 0;
        vector<int> s;
        dfs(root, sum, s, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& s, int& res) {
        if (root == NULL) return;
        
        if (s.empty()) s.push_back(root->val);
        else s.push_back(s.back()+root->val);
        
        if (s.back() == sum) res++;
        for (int i = 0; i+1 < s.size(); i++)
            if (s.back() - s[i] == sum) res++;
        
        if (root->left) dfs(root->left, sum, s, res);
        if (root->right) dfs(root->right, sum, s, res);
        s.pop_back();
    }
};
