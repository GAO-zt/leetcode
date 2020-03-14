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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (root) {
            traversal(root, res);
        }
        return res;
    }

    void traversal(TreeNode* x, vector<int>& res) {
        if (!x) return;
        traversal(x->left, res);
        traversal(x->right, res);
        res.push_back(x->val);
    }
};