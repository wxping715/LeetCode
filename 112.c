/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 
bool verify(struct TreeNode *root, int sum){
    
}

bool hasPathSum(struct TreeNode *root, int sum) {
    
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL)
        return root->val == sum ? true : false;
    
    return (hasPathSum(root->left,sum - root->val) || hasPathSum(root->right, sum - root->val));
    
}