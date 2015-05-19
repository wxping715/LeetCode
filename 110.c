/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
 
int abs(int a){ return a > 0 ? a : -a; }
 
int treeDepth(struct TreeNode *root){
    if(root == NULL) return 0;
    
    int depth1 = treeDepth(root->left);
    int depth2 = treeDepth(root->right);
    
    return depth1 > depth2 ? depth1 + 1 : depth2 + 1;
}

bool isBalanced(struct TreeNode *root) {
    
    if(root == NULL) return true;
    
    if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
    return abs(treeDepth(root->left)-treeDepth(root->right)) > 1 ? false : true;
}