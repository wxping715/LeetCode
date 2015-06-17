/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
/**
 * log(N^2)
 **/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = 0,rh = 0;
        for(struct TreeNode *p=root;p != NULL;p = p->left) lh++;
        for(struct TreeNode *p=root;p != NULL;p = p->right) rh++;
        
        if(lh == rh) return (1<<lh)-1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};
