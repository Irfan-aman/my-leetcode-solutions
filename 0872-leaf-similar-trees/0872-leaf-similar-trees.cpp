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
    void fillLeaves(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        fillLeaves(root->left, arr);
        fillLeaves(root->right, arr);
        if (root->left == NULL && root->right == NULL) {
            arr.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Leaves;
        vector<int> root2Leaves;
        fillLeaves(root1, root1Leaves);
        fillLeaves(root2, root2Leaves);
        if (root1Leaves.size() == root2Leaves.size()) {
            for (int i = 0; i < root1Leaves.size(); i++) {
                if (root1Leaves[i] != root2Leaves[i]) {
                    return false;
                }
            }
        } else
            return false;
        return true;
    }
};