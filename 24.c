/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *pre = head, *p = head->next, *q;
    q = swapPairs(p->next);
    pre->next = q;
    p->next = pre;
    return p;
}
