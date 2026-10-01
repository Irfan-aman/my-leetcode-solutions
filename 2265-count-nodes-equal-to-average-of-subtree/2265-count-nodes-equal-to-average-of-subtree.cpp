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
    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto leftS = solve(root->left);
        auto rightS = solve(root->right);
        int totalSum = leftS.first + rightS.first + root->val;
        int totalCount = leftS.second + rightS.second + 1;
        int average = totalSum / totalCount;
        if (root->val == average)
            result++;
        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        solve(root);
        return result;
    }
};