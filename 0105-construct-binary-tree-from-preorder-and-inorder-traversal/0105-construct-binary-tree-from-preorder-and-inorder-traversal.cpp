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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int left,
                    int right, int& preIdx) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inorderIdx = search(inorder, left, right, root->val);
        root->left = solve(preorder, inorder, left, inorderIdx - 1, preIdx);
        root->right = solve(preorder, inorder, inorderIdx + 1, right, preIdx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return solve(preorder, inorder, 0, preorder.size() - 1, preIdx);
    }
};