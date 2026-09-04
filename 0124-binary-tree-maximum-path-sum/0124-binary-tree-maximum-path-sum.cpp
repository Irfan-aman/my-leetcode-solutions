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
    int maxSum;
    int maxPathSumHelper(TreeNode* root) {
        if (!root)
            return 0;
        int L = maxPathSumHelper(root->left);
        int R = maxPathSumHelper(root->right);
        int bothLR = L + R + root->val;
        int eitherLR = max(L, R) + root->val;
        int neitherLR = root->val;
        maxSum = max({maxSum, bothLR, eitherLR, neitherLR});
        return max(eitherLR, neitherLR);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathSumHelper(root);
        return maxSum;
    }
};