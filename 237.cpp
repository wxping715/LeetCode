/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(node == NULL) return;
    if(node->next == NULL) return;
    
    node->val = node->next->val;
    node->next = node->next->next;
}
