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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return nullptr;
        ListNode *dummy_head_a = new ListNode(-1);
        ListNode *dummy_head_b = new ListNode(-1);
        ListNode *pt = head;
        ListNode *pt_a = dummy_head_a; 
        ListNode *pt_b = dummy_head_b;
        while(pt != nullptr) {
            if(pt->val < x) {
                pt_a->next = pt;
                pt_a = pt_a->next;
            }
            else {
                pt_b->next = pt;
                pt_b = pt_b->next;              
            } 
            pt = pt->next;
        }
        pt_a->next = dummy_head_b->next;   
        pt_b->next = nullptr;
      
        return dummy_head_a->next;
    }
};