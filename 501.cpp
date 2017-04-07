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


    /*
    * O(N) time, O(1) space
    */
    vector<int> findMode(TreeNode* root) {
        int maxf = 0, pre = INT_MIN, cnt = 0;
        vector<int> res;
        
        inorder(root, maxf, pre, cnt);
        pre = INT_MIN, cnt = 0;
        getMode(root, maxf, pre, cnt, res);
        return res;
    }
    
    void getMode(TreeNode* root, int maxf, int& pre, int& cnt, vector<int>& res) {
        if (!root) return;
        getMode(root->left, maxf, pre, cnt, res);
        
        cnt = (pre == root->val ? cnt+1 : 1);
        pre = root->val;
        if (maxf == cnt) res.push_back(root->val);
        
        getMode(root->right, maxf, pre, cnt, res);
    }
    
    void inorder(TreeNode* root, int& maxf, int& pre, int& cnt) {
        if (!root) return;
        
        inorder(root->left, maxf, pre, cnt);
        
        cnt = (pre == root->val ? cnt+1 : 1);
        maxf = max(maxf, cnt);
        pre = root->val;
        
        inorder(root->right, maxf, pre, cnt);
    }
};
