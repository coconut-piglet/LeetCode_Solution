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
    ListNode* deleteDuplicates(ListNode* head) {
        // First Attempt
        // ListNode* ptr1 = head;
        // ListNode* ptr2;
        // while (ptr1 != nullptr) {
        //     ptr2 = ptr1 -> next;
        //     while (ptr2 != nullptr) {
        //         if (ptr2 -> val == ptr1 -> val) {
        //             ptr2 = ptr2 -> next;
        //             ptr1 -> next = ptr2;
        //             continue;
        //         }
        //         break;
        //     }
        //     ptr1 = ptr2;
        // }
        // return head;
        // Optimized Solution
        ListNode* ptr = head;
        while (ptr != nullptr && ptr -> next != nullptr) {
            if (ptr -> next -> val == ptr -> val) {
                ptr -> next = ptr -> next -> next;
            }
            else {
                ptr = ptr -> next;
            }
        }
        return head;
    }
};