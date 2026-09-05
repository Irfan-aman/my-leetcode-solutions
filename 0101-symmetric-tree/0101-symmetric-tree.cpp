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
    bool isSymHelper(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return l->val == r->val && isSymHelper(l->left, r->right) &&
               isSymHelper(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymHelper(root->left, root->right);
    }
};