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
        ListNode *ret, *tmp0;
        int count;
        
        ret = new ListNode(0);
        ret->next = head;
        head = ret;
        while (true) { // TODO: add condition
            tmp0 = head;
            for (count = k; count > 0 && tmp0 != nullptr; count--) {
                tmp0 = tmp0->next;
            }
            if (count != 0) break;
             
        }
        return ret;
    }
private:
    ListNode* swapHead(ListNode* head, ListNode* tailBegin, ListNode* tailEnd) {
        
    }
};