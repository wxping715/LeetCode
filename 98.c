/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root,int flag){
    
    int res = root->val;
    if(root->left != NULL){
        int left_res = dfs(root->left,flag);
        if(flag == 0)
            res = res < left_res ? res : left_res;
        else
            res = res > left_res ? res : left_res;
    }
    if(root->right != NULL){
        int right_res = dfs(root->right,flag);
        if(flag == 0)
            res = res < right_res ? res : right_res;
        else
            res = res > right_res ? res : right_res;
    }
    return res;
}
 
bool isValidBST(struct TreeNode* root) {
    
    if(root == NULL) return true;
       
    if(!isValidBST(root->left)) return false;
    if(!isValidBST(root->right)) return false;
       
    int val = root->val;
    if(root->left != NULL){
        int max = dfs(root->left,1);
        if(max >= val) return false;
    }
    if(root->right != NULL){
        int min = dfs(root->right,0);
        if(min <= val) return false;
    }
    return true;
}
