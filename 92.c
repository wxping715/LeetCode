/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode *reverseList(struct ListNode* head){
    struct ListNode *p,*q,*r;
    
    p = NULL; q = head; r = head;
    while(q != NULL){
        r = q->next;
        
        q->next = p;
        p = q;
        q = r;
    }
    return p;
} 

struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    
    int cnt = 0;
    
    struct ListNode *pre = head,*mid,*last,*p = head,*q = NULL;
    
    while(p != NULL){
        cnt++;
        
        if(cnt == m){
            if(q == NULL) pre = NULL;
            else q->next = NULL;
            mid = p;
        }
        if(cnt == n){
            last = p->next;
            p->next = NULL;
        }
        
        q = p;
        p = p->next;
    }
    
    mid = reverseList(mid);
    p = mid;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = last;
    
    if(pre == NULL) pre = mid;
    else{
        p = pre;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = mid;
    }
    
    return pre;
}
