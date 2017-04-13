/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* rhead = NULL, *rear = NULL, *p = head, *q = head;
        ListNode* t;
        int cur;
        
        // tricky input: [1], 2
        int len = 0;
        p = head;
        while (p) {
            len++;
            p = p->next;
        }
        
        if (len < k) return head;
        
        while (q) {
            cur = 0;
            p = q;
            while (q) {
                cur++;
                if (cur == k) break;
                q = q->next;
            }
            
            // connect with the current list
            if (cur < k) {
                rear->next = p;
            } else {
                // disconnect with the later part
                t = q;
                q = q->next;
                t->next = NULL;
                
                // reverse it
                pair<ListNode*, ListNode*> np = reverse(p);
                if (!rhead) rhead = np.first;
                else rear->next = np.first;
                rear = np.second;
                rear->next = NULL;
            }
        }
        return rhead;
    }
    
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* rhead = NULL, *p = head, *q = NULL, *rear;
        while (p) {
            q = p->next;
            if (rhead == NULL) 
                rear = p;
            p->next = rhead;
            rhead = p;
            p = q;
        }
        return make_pair(rhead, rear);
    }
};
