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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* ret = new ListNode(0);
        ret->next = head;
        head = ret;
        
        ListNode *fst, *snd;
        fst = head->next;
        snd = fst->next;
        
        
        while (snd != nullptr) {
            if (snd->val == fst->val) { // skip duplicates of current node
                snd = snd->next;
            }
            else if (fst->next == snd) { // keep current node
                head->next = fst;
                head = fst;
                fst = snd;
                snd = snd->next;
            }
            else { // skip current node
                fst = snd;
                snd = snd->next;
            }
        }
        
        if (fst->next == nullptr) { // deal with one last candidate
            head->next = fst;
            head = fst;
        }
        else if (ret->next == fst) { // deal with corner case where all nodes are the same
            return nullptr;
        }
        
        head->next = nullptr; // clear tails
        
        return ret->next;
    }
};