/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode*p,*q;
    
    p = head; q = head;
    bool flag = false;
    while(true){
        if(q == NULL) return false;
        if(p == q && flag) return true;
        
        flag = true;
        p = p->next;
        q = q->next;
        if(q == NULL) return false;
        q = q->next;
    }
}