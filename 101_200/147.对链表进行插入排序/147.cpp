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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev_check = dummy->next;
        while(prev_check != nullptr && prev_check->next != nullptr) {
            ListNode *insert = dummy;
            ListNode *check = prev_check->next;
            int is_del = 0;
            // 如果新移动的节点已经不小于前一节点，那么已经有序，不再遍历
            if(prev_check->val < prev_check->next->val) {
                prev_check = prev_check->next;
                continue;
            }
            while(insert != prev_check && prev_check->next != nullptr && insert != nullptr && insert->next != nullptr) {              
                // printf("insert->next->val = %d, prev_check->next->val = %d\n", insert->next->val, prev_check->next->val);
                if(prev_check->next->val < insert->next->val) {
                    // del from current position.       
                    prev_check->next = prev_check->next->next;
                    // insert in new position.
                    check->next = insert->next;
                    insert->next = check;
                    is_del = 1;
                    break;
                }
                insert = insert->next;                
            }  
            //如果之前被删除的话那么prev_check已经前进到下一个节点了            
            if(!is_del) prev_check = prev_check->next; 
                // printf("prev_check->next->val = %d\n", prev_check->next->val);
            // for(ListNode *p = dummy->next;p != nullptr; p = p->next) {
            //     printf("%d->", p->val);
            // } 
            printf("\n");
        }
        return dummy->next;
    }
};