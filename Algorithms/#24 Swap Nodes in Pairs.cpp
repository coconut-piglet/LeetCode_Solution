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
        ListNode *ret, *tmp0, *tmp1;
        
        ret = new ListNode(0);
        ret->next = head;
        head = ret;
        while (head->next != nullptr && head->next->next != nullptr) {
            tmp0 = head->next;
            tmp1 = head->next->next;
            head->next = tmp1;
            tmp0->next = tmp1->next;
            tmp1->next = tmp0;
            head = tmp0;
        }
        return ret->next;
    }
};