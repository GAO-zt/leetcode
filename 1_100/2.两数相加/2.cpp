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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;        
        
        ListNode* head = new ListNode(0);
        int temp_sum = 0;
        int carry_in = 0;
        int add_1 = 0;
        int add_2 = 0;
        ListNode* curr = head;
      
        while(l1 != nullptr || l2 != nullptr) {
            add_1 = (l1 != nullptr) ? l1->val : 0;
            add_2 = (l2 != nullptr) ? l2->val : 0;
               
            temp_sum = add_1 + add_2 + curr->val;               
            curr->val = temp_sum % 10; 
            carry_in = (temp_sum) / 10;
               
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
                      
            if(l1 != nullptr || l2 != nullptr) {
                curr->next = new ListNode(carry_in);  
            }
            else if (carry_in > 0) {
                curr->next = new ListNode(carry_in);
            }
                     
            if(curr != nullptr) curr = curr->next;
        }
        return head;       
    }
};