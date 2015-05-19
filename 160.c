/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(headA == NULL || headB == NULL) return NULL;
    
    struct ListNode *p,*q,*r;
    
    p = headA;
    while(p->next != NULL)  p = p->next;
    r = p;
    p->next = headA;
    
    p = headB; q = headB;
    bool flag = false;
    bool inters = false;
    while(true){
        
        if(q == NULL) break;
        if(p == q && flag){
            inters = true;
            break;
        } 
        
        flag = true;
        p = p->next;
        q = q->next;
        if(q == NULL) break;
        q = q->next;
    }
    
    if(inters){
        p = headB;
        while(p != q){
            p = p->next;
            q = q->next;
        }   
    }
    r->next = NULL;
    
    if(inters) return q;
    return NULL;
}