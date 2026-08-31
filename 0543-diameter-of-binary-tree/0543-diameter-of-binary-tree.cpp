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
    pair<int, int> diamAndHt(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto leftInfo = diamAndHt(root->left);
        auto rightInfo = diamAndHt(root->right);
        int ht = 1 + max(leftInfo.second, rightInfo.second);
        int diam = max({leftInfo.first, rightInfo.first,
                        1 + leftInfo.second + rightInfo.second});
        return {diam, ht};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diamAndHt(root).first - 1;
    }
};