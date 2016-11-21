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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        list = head;
        size = 0;
        seed = -1;
        
        ListNode *p = head;
        while (p) {
            size++;
            p = p->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        srand(seed);
        seed = rand();
        int ridx = seed%size;
        
        ListNode* p = list;
        while (ridx) {
            p = p->next;
            ridx--;
        }
        return p->val;
    }

private:
int size;
ListNode* list;
int seed;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */


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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        list = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
       ListNode* p = list;
       int val, step = 1;
       while (p != NULL) {
           int ridx = rand()%(step++);
           if (ridx == 0) val = p->val;
           p = p->next;
       }
       return val;
    }
private:
    ListNode* list;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
