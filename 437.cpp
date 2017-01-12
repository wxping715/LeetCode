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
        int res = 0, csum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        dfs(root, csum, sum, hash, res);
        return res;
    }
    
    void dfs(TreeNode* root, int csum, int target, unordered_map<int, int>& hash, int& res) {
        if (root == NULL) return;
        csum += root->val;
        if (hash.count(csum-target)) res += hash[csum-target];
        hash[csum]++;
        
        if (root->left) dfs(root->left, csum, target, hash, res);
        if (root->right) dfs(root->right, csum, target, hash, res);
        
        hash[csum]--;
    }
};
