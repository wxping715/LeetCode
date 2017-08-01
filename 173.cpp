/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        p = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (p || !s.empty());
    }

    /** @return the next smallest number */
    int next() {
        while (p) {
           s.push(p);
           p = p->left;
        }
        
        p = s.top();
        s.pop();
        int val = p->val;
        p = p->right;
        return val;
    }
    
private:
    stack<TreeNode*> s;
    TreeNode* p;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
