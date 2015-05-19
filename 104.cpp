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
    int maxDepth(TreeNode *root) {
       
        if(root == NULL) return 0;
        
        int max = 0;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            max++;
            
            for(int i = 0,n = q.size();i < n;i++){
                TreeNode *p = q.front();
                q.pop();
                
                if(p->left != NULL) q.push(p->left);
                if(p->right != NULL) q.push(p->right);
            }
        }
        return max;
    }
};