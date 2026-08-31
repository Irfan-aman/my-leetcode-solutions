/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* delNodHelper(TreeNode* root, unordered_set<int>& st,
                           vector<TreeNode*>& res) {
        if (!root)
            return NULL;
        root->left = delNodHelper(root->left, st, res);
        root->right = delNodHelper(root->right, st, res);
        if (st.count(root->val)) {
            if (root->left != NULL)
                res.push_back(root->left);
            if (root->right != NULL)
                res.push_back(root->right);
            return NULL;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        delNodHelper(root, st, res);
        if (st.count(root->val) == 0) {
            res.push_back(root);
        }
        return res;
    }
};