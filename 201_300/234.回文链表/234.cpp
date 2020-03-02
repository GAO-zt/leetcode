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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode *pt_slow = head;
        ListNode *pt_fast = head;
        while(pt_slow != nullptr && pt_fast != nullptr && pt_fast->next != nullptr) {
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next->next;
        }
        ListNode *curr = pt_slow;
        ListNode *prev = nullptr;  
        ListNode *next = nullptr;
        while(curr != nullptr) {
            next = curr->next;        
            curr->next = prev;
            prev = curr;
            curr = next;         
        }
        ListNode *pt_forward = head;
        ListNode *pt_backward = prev;
        while(pt_forward != nullptr && pt_backward != nullptr) {
            if(pt_forward->val != pt_backward->val) {
                return false;
            }
            pt_forward = pt_forward->next;
            pt_backward = pt_backward->next;
        }
        return true;
    }
};