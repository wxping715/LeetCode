/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 
struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode *p = head,*q = head;
    bool flag = false;
    while(true){
        if(q == NULL) return NULL;
        if(p == q && flag) break;
        
        flag = true;
        p = p->next;
        q = q->next;
        if(q == NULL) return NULL;
        q = q->next;
    }
    
    p = head;
    while(p != q){
        p = p->next;
        q = q->next;
    }
    return p;
}