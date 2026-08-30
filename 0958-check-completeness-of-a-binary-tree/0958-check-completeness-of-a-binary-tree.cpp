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
    int countNode(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
    bool dfs(TreeNode* root, int idx, int totalNodes) {
        if (root == NULL)
            return true;
        if (idx > totalNodes)
            return false;
        return dfs(root->left, 2 * idx, totalNodes) &&
               dfs(root->right, 2 * idx + 1, totalNodes);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNode(root);
        return dfs(root, 1, totalNodes);
    }
};