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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (root) {
            stack<TreeNode*> s;
            while (true) {
                goAlongLeft(root, s);
                if (s.empty()) break;
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }

    void goAlongLeft(TreeNode* x, stack<TreeNode*>& s) {
        // 注意中序遍历时只是压栈，而不访问
        while (x) {
            s.push(x);
            x = x->left;
        }
    }
};