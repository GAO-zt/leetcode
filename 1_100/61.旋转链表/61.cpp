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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(-1);      
        dummy_head->next = head;
        ListNode *tail = head;
        int size = 0;

        while(tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
            size++;
        }
        size++;
        tail->next = head;
        int pt_mov = size - (k % size);
        for(int step = 0;step < pt_mov; step++) {
            dummy_head->next = dummy_head->next->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy_head->next;
    }
};