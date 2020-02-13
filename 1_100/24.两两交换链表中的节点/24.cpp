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

    void swapNodes(ListNode* prev, ListNode* a, ListNode* b) {      
        ListNode* bnext = b->next;        
        prev->next = b;
        b->next = a;
        a->next = bnext;   
    }      
    
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* p = dummy_head; 
        while(p != nullptr && p->next != nullptr && p->next->next != nullptr) {
            swapNodes(p, p->next, p->next->next);
            p = p->next->next;                
        }
        return dummy_head->next;        
    }
      
};