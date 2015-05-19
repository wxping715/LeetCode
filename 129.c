/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */

int num[100],depth,sum = 0;
 
int calnum()
{
    int i = 0,res = 0;
    while(i <= depth)
    {
        res = res * 10 + num[i];
        i++;
    }
    return res;
}
 
void dfs(struct TreeNode *root)
{
    num[depth] = root->val;
    if(root->left == NULL && root->right == NULL){
        sum += calnum();
        return;
    }
    
    if(root->left != NULL){
         depth++;
         dfs(root->left);
         depth--;
    }if(root->right != NULL){
        depth++;
        dfs(root->right);
        depth--;
    }
}
 
int sumNumbers(struct TreeNode *root) {
    
    if(root == NULL) return 0;
    
    sum = 0;depth = 0;
    dfs(root);
    return sum;
}