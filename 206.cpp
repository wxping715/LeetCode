/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct  ListNode *p = NULL, *q = head, *r = NULL;
    
    while(q != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}
