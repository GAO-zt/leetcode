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
        travsal(root);
        return res;
    }

    void travsal(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        travsal(root->left);
        travsal(root->right);        
    }
};