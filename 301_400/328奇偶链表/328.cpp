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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        else if(head->next == nullptr) {
            return head;
        }
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;                
    
        while(even != nullptr && even->next != nullptr && odd != nullptr && odd->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;

        return head;
    }
};