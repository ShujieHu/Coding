//typical example of swapping nodes in pairs in ListNodes
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        }
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        p = head;
        if (len == 1) {
            return head;
        }
        //general case: when len >= 2
        ListNode* dum = new ListNode(0);
        head = dum;
        
        while(p && p->next) {
            ListNode* q = p->next;
            ListNode* t = q->next;
            dum->next = q;
            dum = dum->next;
            dum->next = p;
            dum = dum->next;
            p = t;
        }
        //possible case when p exists while p->next does not
        if (p) {
            dum->next = p;
            dum = dum->next;
        }
        dum->next = NULL;
        dum = head;
        head = dum->next;
        delete dum;
        return head;
    }
};
