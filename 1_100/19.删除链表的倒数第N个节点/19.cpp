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
        if(head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        
        ListNode *p_del = dummy_head;
        ListNode *p = head;
        for(int i=0;i<n;i++) {
            p = p->next;
        }
        while(p != nullptr) {
            p_del = p_del->next;
            p = p->next;         
        }
        p_del->next = p_del->next->next;
        return dummy_head->next;
    }
};