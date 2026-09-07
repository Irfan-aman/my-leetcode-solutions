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
    int res;
    void solve(TreeNode* root, int curr) {
        if (!root) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            res += curr;
            return;
        }

        if (root->left)
            solve(root->left, curr * 10 + root->left->val);
        if (root->right)
            solve(root->right, curr * 10 + root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        solve(root, root->val);
        return res;
    }
};