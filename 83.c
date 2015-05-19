/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL) return head;
    
    //int prev = 999999999;
    
    struct ListNode *p = head,*q = p->next;
    int prev = p->val;
    while(q != NULL){
        if(q->val == prev){
            p->next = q->next;
            free(q);
            q = p->next;
        }else{
            prev = q->val;
            p = p->next;
            q = q->next;
        }
    }
    return head;
}