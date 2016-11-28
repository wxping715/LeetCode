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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        deque<ListNode *> qlists(lists.begin(), lists.end());
        
        while (qlists.size() > 1) {
            int n = qlists.size();
            for (int j = 0; j < n-1; j += 2) {
                ListNode* l1 = qlists.back(); qlists.pop_back();
                ListNode* l2 = qlists.back(); qlists.pop_back();
                
                ListNode* nlist = mergeTwoLists(l1, l2);
                qlists.push_front(nlist);
            }
        }
        return qlists.back();
    }
    
    ListNode *mergeTwoLists(ListNode* &a, ListNode* &b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        
        ListNode *head = NULL, *rear = NULL, *p1 = a, *q1, *p2 = b, *q2;
        while (p1 && p2) {
            int lid = p1->val < p2->val ? 1 : 2;
            ListNode *p = p1->val < p2->val ? p1 : p2;
            if (lid == 1) q1 = p1->next; 
            else if(lid == 2) q2 = p2->next;
            
            p->next = NULL;
            if (rear == NULL) {
                rear = p;
                head = p;
            } else {
                rear->next = p;
                rear = p;
            }
            
            if (lid == 1) p1 = q1;
            else p2 = q2;
        }
        if (p1) rear->next = p1;
        else rear->next = p2;
        
        return head;
    }
};
