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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *a_pt = headA;
        ListNode *b_pt = headB;
        int len_a = 0;
        int len_b = 0;
        while(a_pt != nullptr) {
            a_pt = a_pt->next;
            len_a++;
        }
        while(b_pt != nullptr) {
            b_pt = b_pt->next;
            len_b++;
        }
        a_pt = headA;
        b_pt = headB;
        if(len_a > len_b) {
            for(int i=0;i<(len_a - len_b);i++) {
                a_pt = a_pt->next;
            }
        }
        else {
            for(int i=0;i<(len_b - len_a);i++) {
                b_pt = b_pt->next;
            }            
        }
        while(a_pt != nullptr && b_pt != nullptr) {
            if(a_pt == b_pt) {
                return a_pt;
            }
            a_pt = a_pt->next;
            b_pt = b_pt->next;
        }
   
        return nullptr;
    }
};