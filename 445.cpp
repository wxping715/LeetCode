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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        int len1 = 0, len2 = 0;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 != NULL) {
            len1++;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            len2++;
            p2 = p2->next;
        }
        
        ListNode *longl, *shortl;
        if (len1 > len2) {
            longl = l1;
            shortl = l2;
        } else {
            longl = l2;
            shortl = l1;
        }
        int diff = abs(len1-len2);
        
        p1 = longl, p2 = shortl;
        ListNode *resl = NULL;
        while (p1 != NULL) {
            int val = diff > 0 ? p1->val : p1->val + p2->val;
            p1 = p1->next;
            if (diff <= 0) p2 = p2->next;
            
            ListNode *node = new ListNode(val);
            node->next = resl;
            resl = node;
            diff--;
        }
        
        // print(resl);
        
        int carry = 0;
        p1 = resl;
        while (p1 != NULL) {
            int temp = carry;
            carry = (p1->val+carry)/10;
            p1->val = (temp+p1->val)%10;
            p1 = p1->next;
        }
        resl = reverse(resl);
        
        if (carry != 0) {
            ListNode* node = new ListNode(1);
            node->next = resl;
            resl = node;
        }
        return resl;
    }
    
    void print(ListNode *l1) {
        ListNode* p = l1;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    ListNode* reverse(ListNode *l1) {
        if (l1 == NULL || l1->next == NULL) return l1;
        ListNode *nl = NULL, *p = l1, *q;
        while (p != NULL) {
            q = p->next;
            p->next = nl;
            nl = p;
            p = q;
        }
        return nl;
    }
};
