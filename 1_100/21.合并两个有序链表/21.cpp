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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* dummy_head = new ListNode(0);
        ListNode* l1_pt = l1;
        ListNode* l2_pt = l2;
        ListNode* curr = dummy_head;
        while(l1_pt != nullptr || l2_pt != nullptr) {
            int min;
            if(l1_pt == nullptr) {
                min = l2_pt->val;
                if(l2_pt != nullptr) {
                    l2_pt = l2_pt->next;
                }
            }
            else if(l2_pt == nullptr) {
                min = l1_pt->val;
                if(l1_pt != nullptr) {
                    l1_pt = l1_pt->next;
                }                
            }
            else if (l1_pt->val < l2_pt->val) {
                min = l1_pt->val;
                l1_pt = l1_pt->next;               
            }  
            else {
                min = l2_pt->val;
                l2_pt = l2_pt->next;                                         
            }
            printf("min = %d\n", min);
            curr->next = new ListNode(min);   
            curr = curr->next;
        }
        return dummy_head->next;
    }
};