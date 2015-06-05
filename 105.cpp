/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int find(vector<int> v, int key, int l,int r){
        if(l > r) return -1;
        for(int i = l;i <= r;i++)
            if(v[i] == key) return i;
        return -1;
    }

    struct TreeNode* createNode(int val){
        struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        
        return p;
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr,int il,int ir){
        if(pl > pr || il > il) return NULL;
        
        if(pl == pr && il == ir)  return createNode(preorder[pl]);
        
        struct TreeNode* root = createNode(preorder[pl]);
        int mid = find(inorder,preorder[pl],il,ir);
        if(mid != -1){
            root->left = dfs(preorder,inorder,pl+1,pl+mid-il,il,mid-1);
            root->right = dfs(preorder,inorder,pl+mid-il+1,pr,mid+1,ir);
        }
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        
        return dfs(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
