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
    void insert(ListNode* des, ListNode* src) {
        // src下一个节点插入des的下一节点
        ListNode *des_next = des->next;
        ListNode *src_next_next = src->next->next;
        des->next = src->next;
        src->next->next = des_next;
        src->next = src_next_next;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return nullptr;
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;     
        ListNode *rev_start = dummy_head; 
        ListNode *p = dummy_head;
        for (int i=0; i<n; i++) {
            // 记录反转开始
            if(i == m - 1) rev_start = p;
            if(i > m - 1) {
                // 每次把后一个值插入最前端
                insert(rev_start, p);
            }
            // 在每次从后抽取向前插入时，p其实也在移动，因此开始反向操作之后对p不作修改
            if(i < m) p = p->next;
            // for(auto pt = dummy_head->next; pt != nullptr; pt = pt->next) {
            //     printf("%d->", pt->val);
            // }
            // printf("\n");
        }
        return dummy_head->next;
    }
};