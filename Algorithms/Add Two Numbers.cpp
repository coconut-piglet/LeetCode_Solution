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
        ListNode *ret, *next, *next1, *next2;
        int num1, num2, carryBit, num;
        next1 = l1;
        next2 = l2;
        carryBit = 0;
        ret = new ListNode(-1);
        next = ret;
        while (l1 != nullptr || l2 != nullptr) {
            num1 = 0;
            num2 = 0;
            if (l1) {num1 = l1->val; l1 = l1->next;}
            if (l2) {num2 = l2->val; l2 = l2->next;}
            num = num1 + num2 + carryBit;
            carryBit = 0;
            if (num > 9) {
                num = num - 10;
                carryBit = 1;
            }
            next->next = new ListNode(num);
            next = next->next;
        }
        if (carryBit) next->next = new ListNode(1);
        ret = ret->next;
        return ret;
    }
};