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
    int res = 0;
    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int sum = root->val + left.first + right.first;
        int size = (1 + left.second + right.second);
        if (sum / size == root->val)
            res++;
        return {sum, size};
    }
    int averageOfSubtree(TreeNode* root) {
        if (!root)
            return 0;
        solve(root);
        return res;
    }
};