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
    int result;
    int st;
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        int leftH = solve(root->left);
        int rightH = solve(root->right);
        if (root->val == st) {
            result = max(leftH, rightH);
            return -1;
        } else if (leftH >= 0 && rightH >= 0) {
            return max(leftH, rightH) + 1;
        } else {
            result = max(result, abs(leftH) + abs(rightH));
            return min(leftH, rightH) - 1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        result = 0;
        st = start;
        solve(root);
        return result;
    }
};