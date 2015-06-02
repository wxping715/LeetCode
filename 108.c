/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode *createNode(int val){
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->left = NULL;
    p->right = NULL;
    p->val = val;
    
    return p;
}
struct TreeNode *dfs(int l,int r,int *nums){
    if(l == r)  return createNode(nums[l]);
    if(l > r) return NULL;
    
    int mid = (l+r)/2;
    struct TreeNode *p = createNode(nums[mid]);
    
    p->left = dfs(l,mid-1,nums);
    p->right = dfs(mid+1,r,nums);
    
    return p;
} 

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return dfs(0,numsSize-1,nums);
}
