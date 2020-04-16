/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// 参考题目144的前序遍历，不同之处在于把访问值插入队首，而且栈是沿着右端遍历
// 正好与前序遍历相反
// 用了一个list来做前端插入，其实vector也可以
    
    std::list<int> res;
    
    vector<int> postorderTraversal(TreeNode* root) {

        std::stack<TreeNode*> s; // 辅助 stack
        while (true) {
            travsalAlongRight(root, s);
            if (s.empty()) break;    
            root = s.top();
            s.pop();
        }
        // 或者也可以对一个vector做reverse
        return vector<int>(res.begin(), res.end());        
    }

    void travsalAlongRight(TreeNode* x, std::stack<TreeNode*>& s) {
        while (x) { // x != nullptr
            res.push_front(x->val);
            if (x->left != nullptr) {
                s.push(x->left);
            }
            x = x->right;
        }
    }
};