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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *p = head;
        ListNode *dup_start = dummy_head;
        while (p != nullptr) {
            // 注意p到末尾的特殊情形, 短路判断
            if (p->next == nullptr || p->val != p->next->val) {
                if(dup_start->next == p) {
                // 前后相邻，说明前面只有1个单独的元素
                    dup_start = dup_start->next;
                }
                else {
                // 前后不相邻，说明前面有2个以上相同元素 ，执行删除
                    dup_start->next = p->next;
                }       
            }
            p = p->next;
        }
        return dummy_head->next;
    }
};