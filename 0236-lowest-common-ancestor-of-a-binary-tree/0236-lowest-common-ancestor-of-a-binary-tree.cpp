/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA = NULL;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return 0;
        int L = solve(root->left, p, q);
        int R = solve(root->right, p, q);
        int match = root == p || root == q;
        int totalMatch = match + L + R;
        if (totalMatch == 2 && LCA == NULL) {
            LCA = root;
        }
        return totalMatch;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return LCA;
    }
};