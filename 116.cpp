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
