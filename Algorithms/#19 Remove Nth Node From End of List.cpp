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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Solution 1 Intuitive Solution
        // vector<ListNode*> index;
        // ListNode* ptr = head;
        // while (ptr) {
        //     index.emplace_back(ptr);
        //     ptr = ptr -> next;
        // }
        // int toDelete = index.size() - n;
        // if (toDelete == 0) return head -> next;
        // if (n == 1) index[toDelete - 1] -> next = nullptr;
        // else index[toDelete - 1] -> next = index[toDelete + 1];
        // return head;
        // Solution 2 One pass algorithm
        ListNode* dummy = new ListNode(0);// this dummy is used to handle wierd conner case;
        dummy ->next = head;
        ListNode *left = dummy, *right = dummy;
        for (int i = 0; i <= n; i++) {
            right = right -> next;// the right ptr advance n steps beforehead
        }
        while (right) {
            right = right -> next;
            left = left -> next;
        }
        left -> next = left -> next -> next;
        return dummy -> next;
    }
};