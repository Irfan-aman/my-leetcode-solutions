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
    void reverseOddLevHelper(TreeNode*& P, TreeNode*& Q, int level) {
        if (!P && !Q)
            return;
        if (level & 1) {
            swap(P->val, Q->val);
        }
        reverseOddLevHelper(P->left, Q->right, level + 1);
        reverseOddLevHelper(P->right, Q->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOddLevHelper(root->left, root->right, 1);
        return root;
    }
};