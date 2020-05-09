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
        ListNode *ret, *tailBegin, *tailEnd, *tailNext;
        int count;
        
        ret = new ListNode(0);
        ret->next = head;
        head = ret;
        
        while (true) {
            tailBegin = head->next;
            tailEnd = head;
            for (count = k; count > 0; count--) {
                tailEnd = tailEnd->next;
                if (tailEnd == nullptr) break;
            }
            if (count > 0) { // reach end
                break;
            }
            head->next = tailEnd;
            head = tailBegin;
            while (tailBegin != tailEnd) {
                tailNext = tailBegin->next;
                tailBegin->next = tailEnd->next;
                tailEnd->next = tailBegin;
                tailBegin = tailNext;
            }
        }
        return ret->next;
    }
};