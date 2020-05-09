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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* next;
        ListNode* tail = head;
        int shift = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            shift++;
        }
        if (shift == 1) return head;
        shift = shift - (k % shift);
        while (shift) {
            next = head->next;
            head->next = tail->next;
            tail->next = head;
            tail = head;
            head = next;
            shift--;
        }
        return head;
    }
};