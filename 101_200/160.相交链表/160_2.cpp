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
        map<int, ListNode *> a_map;
        ListNode *a_pt = headA;
        ListNode *b_pt = headB;
        while(a_pt != nullptr) {
            a_map[a_pt->val] = a_pt;
            a_pt = a_pt->next;
        }
        while(b_pt != nullptr) {
            if(a_map.find(b_pt->val) != a_map.end() && b_pt == a_map[b_pt->val]) {
                return a_map[b_pt->val];
            }
            else {
                b_pt = b_pt->next;
            }
        }
        return nullptr;
    }
};