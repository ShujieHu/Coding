# this is used to merge k sorted linked list and return it as one list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = merge(lists[i], lists[k - i - 1]);
                
            }
            k = (k + 1) / 2;
            
        }
        return lists[0];
    }
    ListNode* merge(ListNode* L1, ListNode* L2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        ListNode* a = L1;
        ListNode* b = L2;
        while (a && b) {
            if (a-> val > b->val) {
                p->next = b;
                p = p->next;
                b = b->next;
            } else if (a->val <= b->val) {
                p->next = a;
                p = p->next;
                a = a->next;    
            }
        }
        if (!b) {
            p->next = a;
        }
        if (!a) {
            p->next = b;        
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
