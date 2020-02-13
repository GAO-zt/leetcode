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
    ListNode* insertVal(ListNode* ins, int val) {
        ListNode *next = ins->next;
        ins->next = new ListNode(val);
        ins->next->next = next;
        return ins;  
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *dummy_head_l1 = new ListNode(-1);
        dummy_head_l1->next = l1;
        ListNode *dummy_head_l2 = new ListNode(-1);
        dummy_head_l2->next = l2;
        ListNode *p_l1 = l1;
        ListNode *p_l2 = l2;                
        int len_l1 = 0;
        int len_l2 = 0;
        // 遍历得到l1与l2的长度
        for(; p_l1 != nullptr; p_l1 = p_l1->next) {
            len_l1++;
        }
        for(; p_l2 != nullptr; p_l2 = p_l2->next) {
            len_l2++;
        }
        // 判断l1与l2长度然后在高位补0
        ListNode *ins = nullptr;
        if(len_l1 > len_l2) {
            ins = dummy_head_l2;
            for(int i=0;i<(len_l1-len_l2);i++) {
                insertVal(ins, 0);
            }
        }
        else if(len_l2 > len_l1) {
            ins = dummy_head_l1;
            for(int i=0;i<(len_l2-len_l1);i++) {
                insertVal(ins, 0);
            }
        }
        // 对原列表然后直接相加的部分和入栈
        int sum_len = (len_l1 > len_l2) ? len_l1 : len_l2;
        p_l1 = dummy_head_l1->next;
        p_l2 = dummy_head_l2->next;
        vector<int> partial_sum;
        for(int i=0;i<sum_len;i++) {
            partial_sum.push_back(p_l1->val + p_l2->val);
            p_l1 = p_l1->next;
            p_l2 = p_l2->next;
        }
        // 栈出部分和以头插入方式加入求和链表
        ListNode *dummy_head_sum = new ListNode(0);
        int digit = 0;
        int carry = 0;
        while(!partial_sum.empty()) {
            int sum = partial_sum.back() + carry;
            partial_sum.pop_back();
            digit = sum % 10;
            carry = sum / 10;
            insertVal(dummy_head_sum, digit);
        }
        // 如果最高位产生额外进位，额外补一个1
        if(carry != 0) {
            insertVal(dummy_head_sum, carry);
        }
        return dummy_head_sum->next;
    }
};