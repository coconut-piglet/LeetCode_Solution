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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* ptr = ret;
        int val1, val2;
        while (l1 && l2) {
            val1 = l1 -> val;
            val2 = l2 -> val;
            if (val1 < val2) {
                ListNode* next = new ListNode(val1);
                ptr -> next = next;
                ptr = next;
                l1 = l1 -> next;
            }
            else {
                ListNode* next = new ListNode(val2);
                ptr -> next = next;
                ptr = next;
                l2 = l2 -> next;
            }
        }
        if (l1) {
            ptr -> next = l1;
        }
        if (l2) {
            ptr -> next = l2;
        }
        return ret -> next;
    }
};