/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    /* BFS Version */
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        
        int cnt = 0, num = 1, level = 0;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeLinkNode* cur = q.front();
            q.pop();
            cnt++;
            
            if(cnt < num) cur->next = q.front();
            else {
                cur->next = NULL;
                num += 1 << (++level);
            }
            
            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
        }
    }
};


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

     /* Recursion Version */
    void connect(TreeLinkNode *root) {
        if (!root || !root->left || !root->right) 
            return;
        
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        else
            root->right->next = NULL;
        
        connect(root->left);
        connect(root->right);
    }
};


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    /* Un-Recursion Version */
    void connect(TreeLinkNode *root) {
       for (TreeLinkNode* cur = root; cur; cur = cur->left) {
            for (TreeLinkNode* next = cur; next; next = next->next) {
                if (!next->left) break;
                next->left->next = next->right;
                
                if (!next->next) 
                    next->right->next = NULL;
                else 
                    next->righ   st->next = next->next->left;
            }
       }
    }
};
