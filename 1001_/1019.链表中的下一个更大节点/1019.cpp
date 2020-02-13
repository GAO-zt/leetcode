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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == nullptr) return {};
        ListNode *pt = head;
        vector<int> res;
        stack<pair<int,int>> st;
        // 所有元素入栈（即之后从右到左遍历）
        int pt_idx = 0;
        while (pt != nullptr && pt->next != nullptr) {
            // 由于比较顺序和实际出栈顺序可能不同，因此记录下索引
            st.push(make_pair(pt->val, pt_idx));
            pt = pt->next;
            int next_val = pt->val;
            res.push_back(0); // 增加res空间
            pt_idx++;

            // 比较栈中所有可能小于现在值的元素
            while (!st.empty() && st.top().first < next_val) {
                res[st.top().second] = next_val;
                st.pop();
            }
        }
        res.push_back(0);
        return res;
    }
};