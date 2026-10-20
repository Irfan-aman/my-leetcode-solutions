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
    TreeNode* balBST(vector<int>& inorder, int l, int h) {
        if (l > h)
            return NULL;
        int mid = l + (h - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = balBST(inorder, l, mid - 1);
        root->right = balBST(inorder, mid + 1, h);
        return root;
    }
    void inorderTrav(TreeNode* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTrav(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrav(root->right, inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTrav(root, inorder);
        return balBST(inorder, 0, inorder.size() - 1);
    }
};