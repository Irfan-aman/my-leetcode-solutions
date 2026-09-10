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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = curr; // create connection to curr
                    curr = curr->left;
                } else {                // pred->right==curr
                    pred->right = NULL; // remove connection
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};