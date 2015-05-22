/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {

    if(k == 0 || head == NULL) return head;

    struct ListNode *p = head, *pre, *q;
    int len = 0,cnt = 0;
    while(p != NULL){
        p = p->next;
        cnt++;
    }
    k %= cnt;
    
    if(k == 0) return head;
    
    p = head; pre = head;
    for(int i = 0;i < cnt-k;i++)
    {
        p = p->next;
        if(i > 0) pre = pre->next;
    }
    
    pre->next = NULL;
    q = p;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = head;
    head = q;
    
    return head;
}
