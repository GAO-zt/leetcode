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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root) {
            list<TreeNode*> l;
            l.push_back(root);
            
            while (!l.empty()) {
                vector<int> level_val;
                int curr_l_size = l.size(); //记录当前level的结点数，务必提前记录，否则会随着list增长而变化导致错误
                for (int i = 0; i < curr_l_size; ++i) {
                    TreeNode* x = l.front();
                    l.pop_front();
                    level_val.push_back(x->val);
                    if (x->left) l.push_back(x->left);
                    if (x->right) l.push_back(x->right);
                }
                res.push_back(level_val);
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};