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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > gtqueue; // 优先队列的用法
        for (ListNode* list : lists) {
            while (list) {
                gtqueue.push(list -> val);
                list = list -> next;
            }
        }
        ListNode* ret = new ListNode(0);
        ListNode* ptr = ret;
        while (!gtqueue.empty()) {
            ListNode* next = new ListNode(gtqueue.top());
            gtqueue.pop();
            ptr -> next = next;
            ptr = next;
        }
        return ret -> next;
    }
};