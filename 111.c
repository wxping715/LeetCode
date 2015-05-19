/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int minDepth(struct TreeNode *root) {
    
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else if(root->left != NULL && root->right != NULL)
    {
        int l = minDepth(root->left) + 1;
        int r = minDepth(root->right) + 1;
        return l > r ? r : l;
    }
    else if(root->left != NULL) return minDepth(root->left) + 1;
    else if(root->right != NULL) return minDepth(root->right) + 1;
}