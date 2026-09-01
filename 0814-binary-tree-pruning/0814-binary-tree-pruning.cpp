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
    bool pruneHelper(TreeNode*& root) {
        if (!root)
            return false;
        bool leftTree = pruneHelper(root->left);
        bool rightTree = pruneHelper(root->right);
        if (!leftTree && !rightTree && root->val == 0) {
            root = NULL;
            return false;
        }
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        pruneHelper(root);
        return root;
    }
};