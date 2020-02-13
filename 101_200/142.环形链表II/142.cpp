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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        int intersection_flag = 0;
        //判断是否有环
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                intersection_flag = 1;
                break;
            }
        }
        if(!intersection_flag) {
            return nullptr;
        }
        //从head与相遇点开始寻找环入口
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};