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
    int maxPath;
    void solve(TreeNode* root, int step, bool goLeft) {
        if (!root)
            return;
        maxPath = max(maxPath, step);
        if (goLeft) {
            solve(root->left, step + 1, false);
            solve(root->right, 1, true);
        } else {
            solve(root->right, step + 1, true);
            solve(root->left, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        maxPath = 0;
        solve(root, 0, true);
        solve(root, 0, false);
        return maxPath;
    }
};