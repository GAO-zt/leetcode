// 使用了STL中的stack
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
    vector<int> res;

    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        std::stack<TreeNode*> s; // 辅助 stack
        while (true) {
            travsalAlongLeft(root, s);
            if (s.empty()) break;    
            root = s.top();
            s.pop();
        }   
        return res;
    }

    void travsalAlongLeft(TreeNode* x, std::stack<TreeNode*>& s) {
        while (x) { // x != nullptr
            res.push_back(x->val);
            if (x->right != nullptr) {
                s.push(x->right);
            }
            x = x->left;
        }
    }
};