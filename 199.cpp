/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        
        pair<TreeNode*,int> p;
        queue<pair<TreeNode *,int> > q;
        vector<int> res;
        if(root == NULL) return res;
        
        q.push(make_pair(root,1));
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if(q.empty() || q.front().second != p.second)
            res.push_back(p.first->val);        
            
            if(p.first->left != NULL) q.push(make_pair(p.first->left,p.second+1));
            if(p.first->right != NULL) q.push(make_pair(p.first->right,p.second+1));
        }
        return res;
    }
};