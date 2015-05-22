/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head, *q = head, *pre=head;
    int cnt = 0;
    while(p != NULL){
        if(cnt > n-1){
            q = q->next;
        }
        if(cnt > n){
            pre = pre->next;
        }
        p = p->next;
        cnt++;
    }
    
    if(pre == q){
        head = head->next;
    }else{
        pre->next = q->next;
    }
    
    free(q);
    return head;
}
