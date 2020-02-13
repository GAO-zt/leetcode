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
    ListNode* middleNode(ListNode* head) {
        ListNode* it_1x = head;
        ListNode* it_2x = head;
        while(it_2x != nullptr && it_2x->next != nullptr) {
            it_1x = it_1x->next;
            it_2x = it_2x->next->next;
        }
        return it_1x;
    }
};