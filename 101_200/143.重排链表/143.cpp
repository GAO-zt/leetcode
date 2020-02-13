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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *dummy_inv_head = new ListNode(-1);
        ListNode *pt_slow = head;
        ListNode *pt_fast = head;
        while(pt_fast != nullptr && pt_fast->next != nullptr) {
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next->next;
        }
    
        ListNode *pt_inv = pt_slow->next;
        pt_slow->next = nullptr; //断开正向链表
        // get half of the list
        while(pt_inv != nullptr) {
            ListNode *pt_inv_next = pt_inv->next;
            pt_inv->next = dummy_inv_head->next;
            dummy_inv_head->next = pt_inv;
            pt_inv = pt_inv_next;
        }

        // pt_slow = nullptr;

        for(ListNode *p = dummy_head->next;p != nullptr; p = p->next) {
            printf("%d->", p->val);
        }
        printf("\n");

        for(ListNode *p = dummy_inv_head->next;p != nullptr; p = p->next) {
            printf("%d->", p->val);
        }
        printf("\n");        

        ListNode *pt_a = dummy_head->next;
        ListNode *pt_b = dummy_inv_head->next;

        while(pt_a != nullptr && pt_b != nullptr) {
            ListNode *pt_a_next = pt_a->next;
            ListNode *pt_b_next = pt_b->next;
            pt_a->next = pt_b;
            pt_b->next = pt_a_next;
            pt_a = pt_a_next;
            pt_b = pt_b_next;
        }
    }
};