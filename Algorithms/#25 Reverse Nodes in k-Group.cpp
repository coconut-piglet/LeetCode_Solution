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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret, *tailBeginOld, *tailEndOld;
        int count;
        
        ret = new ListNode(0);
        ret->next = head;
        head = ret;
        while (true) {
            tailBeginOld = head->next;
            tailEndOld = head;
            for (count = k; tailEndOld != nullptr & count > 0; count--) {
                tailEndOld = tailEndOld->next;
            }
            if (count > 0 || tailEndOld == nullptr) { // reach end
                break;
            }
            head->next = reverse(tailBeginOld, tailEndOld);
            head = tailBeginOld;
        }
        return ret->next;
    }
private:
    ListNode* reverse(ListNode* tailBegin, ListNode* tailEnd) {
        ListNode* head = tailBegin;
        ListNode* next;
        while (head != tailEnd) {
            next = head->next;
            head->next = tailEnd->next;
            tailEnd->next = head;
            head = next;
        }
        return head;
    }
};