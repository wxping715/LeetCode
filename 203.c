/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    if(head == NULL) return NULL;
    
    struct ListNode *p = NULL, *q = head;
    while(q != NULL)
    {
        if(q->val != val)
        {
            p = q;
            q = q->next;
        }
        else{
            
            if(p == NULL)
            {
                p = q->next;
                free(q);
                q = p;
                p = NULL;
                head = q;
            }
            else{
                 p->next = q->next;
                 free(q);
                 q = p->next;   
            }
        }
    }
    return head;
}
