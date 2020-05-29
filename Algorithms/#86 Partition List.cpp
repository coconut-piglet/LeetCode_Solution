/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        
        /* prepare ret */
        ListNode *ret = new ListNode(0);
        ret->next = head;
        
        /* get tail */
        ListNode *tail = head;
        while (tail->next) tail = tail->next;
        
        /* perform partion by swap node to the end of list */
        ListNode *current = ret, *next, *end = tail;
        for (current = ret, next = current->next; next != end; next = current->next) {
            if (next->val >= x) {
                current->next = next->next;
                tail->next = next;
                tail = next;
                tail->next = nullptr;
            }
            else {
                current = next;
            }
        }
        
        /* prevent tail from disconnecting itself */
        if (tail == end) return head;
        
        /* deal with tail separately */
        if (next->val >= x) {
            current->next = next->next;
            tail->next = next;
            next->next = nullptr;
        }
        return ret->next;
    }
};