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
    int maxDiff = -1;
    void findMaxUtil(TreeNode* root, TreeNode* child) {
        if (!root || !child)
            return;
        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMaxUtil(root, child->left);
        findMaxUtil(root, child->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        findMaxUtil(root, root->left);
        findMaxUtil(root, root->right);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return maxDiff;
    }
};