/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

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
    
    // recursive method
    void flatten(TreeNode* root) {
        TreeNode* tail = flattenSub(root);
        tail = root;
    }
    
    TreeNode* flattenSub(TreeNode* root) {
        if (!root) return root;
        if (!root->left && !root->right) return root;
    
        TreeNode* ltail = flattenSub(root->left);
        TreeNode* rtail = flattenSub(root->right);
        if (!ltail) return rtail;
        else {
            ltail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            if (rtail) return rtail;
            return ltail;
        }
    }
    
    // iterative solution
    // preorder
    /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void flatten(TreeNode root) {
        Deque<TreeNode> deque = new LinkedList<>();
        TreeNode p = root, curr = null;
        while (p != null || !deque.isEmpty()) {
            while (p != null) {
                deque.offerLast(p.right);
                TreeNode left = p.left;
                p.left = p.right = null;
                if (curr != null) curr.right = p;
                curr = p;
                p = left;
            }
            p = deque.pollLast();
        }
    }
}
};
