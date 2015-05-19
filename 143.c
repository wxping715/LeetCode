/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reverseList(struct ListNode* list){
    struct ListNode *p = NULL, *q = list, *r = NULL;
    
    while(q != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
} 
 
void reorderList(struct ListNode *head) {
    
    if(head == NULL) return NULL;
    
    struct ListNode *p = head,*q = head,*r,*t;
    while(q!= NULL){
        
        q = q->next;
        if(q == NULL || q->next == NULL) break;
        q = q->next;
        
        p = p->next;
    }
    q = p->next;
    p->next = NULL;
    
    q = reverseList(q);
    p = head;
    
    while(q != NULL){
        r = q->next;
        q->next = p->next;
        p->next = q;
        
        p = p->next->next;
        q = r;
    }
    return head;
}


