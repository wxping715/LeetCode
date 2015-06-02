/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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
 
struct TreeNode* dfs(struct ListNode* head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) return createNode(head->val);
    
    struct ListNode *pre, *mid, *p, *q;
    pre = head, mid = head, p = head;
    int cnt = 0;
    while(p != NULL){
        p = p->next;
        if(p == NULL) break;
        p = p->next;
        if(p == NULL) break;
        
        if(cnt > 0) pre = pre->next;
        mid = mid->next;
        cnt++;
    }
    
    struct TreeNode *node = createNode(mid->val);
    if(cnt >  0){
        pre->next = NULL; 
        node->left = dfs(head);
    }else{
        node->left = NULL;
    }
    node->right = dfs(mid->next);
    
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return dfs(head);
}
