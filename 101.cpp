/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
bool checkLeftRight(struct TreeNode *left,struct TreeNode *right){
    if(left == NULL && right == NULL) return true;
    if((left == NULL && right != NULL) || (left != NULL && right == NULL)) return false;
    
    if(left->val != right->val) return false;
    
    return (checkLeftRight(left->left,right->right) && checkLeftRight(left->right,right->left));
}
 
bool isSymmetric(struct TreeNode *root) {
    if(root == NULL) return true;
    else return checkLeftRight(root->left,root->right);
}
