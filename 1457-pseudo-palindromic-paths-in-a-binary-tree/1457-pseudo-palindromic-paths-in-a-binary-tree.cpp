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
    void solve(TreeNode* root, int& bit) {
        if (!root)
            return;
        int x = root->val;
        bit ^= (1 << x);
        if (root->left == NULL && root->right == NULL) {
            if ((bit & (bit - 1)) == 0) // only  one bit set
                res++;
        }
        solve(root->left, bit);
        solve(root->right, bit);
        bit ^= (1 << x);
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        res = 0;
        int bit = 0;
        solve(root, bit);
        return res;
    }
};