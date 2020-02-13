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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
     
        while(curr != NULL) {                
            next = curr->next; //暂存下一节点（因之后会修改）
            curr->next = prev; //修改下一节点指向前一节点
            prev = curr; //前一节点遍历
            curr = next; //当前节点遍历
        }
        
        return prev;
    }
};