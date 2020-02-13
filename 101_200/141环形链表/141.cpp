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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *pt_slow = head;
        ListNode *pt_fast = head->next;
        while(pt_slow != nullptr && pt_fast != nullptr && pt_fast->next != nullptr) {
            if(pt_slow == pt_fast) {
                return true;
            }
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next->next;
        }
        return false;
    }
};