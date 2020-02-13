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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {        
        // 对于null的情形，由于要返回多个null，于是仍然进行正常路径的处理
        vector<ListNode*> ret;      
        int len = 0;
        // 获取链表长度
        for(auto p = root; p != nullptr; p=p->next) {
            len++;
        }
        // 每个段的最小长度和分配额外长度，并保存
        int avg_split_num = len / k;
        int extra_split_num = len % k;
        vector<int> split_num;
        for(int i=0;i<k;i++) {
            split_num.push_back(avg_split_num + (extra_split_num > 0));
            if(extra_split_num > 0) extra_split_num--;
        }

        ListNode *next_split_start = root;
        int split_idx = 0;
        while(split_idx < k) {
            ListNode *curr_split_dummy_head = new ListNode(-1);
            // 每次构建一个新的dummy指向上一次循环的保存地址
            curr_split_dummy_head->next = next_split_start;
            ListNode *it = curr_split_dummy_head;
            if(it != nullptr && it->next != nullptr) {
                for(int i=0;i<split_num[split_idx];i++) {
                    it = it->next;
                }
                // 保存下一元素的地址
                next_split_start = it->next;
                it->next = nullptr;
                ret.push_back(curr_split_dummy_head->next);
            }
            // 不足的元素要补null
            else {
                ret.push_back(nullptr);
            }
            split_idx++;
        }
        return ret;
    }
};