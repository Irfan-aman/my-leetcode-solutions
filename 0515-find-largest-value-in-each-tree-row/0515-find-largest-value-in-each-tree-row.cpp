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
    void dfs(TreeNode* root, int depth, vector<int>& res) {
        if (res.size() == depth) {
            res.push_back(root->val);
        } else {
            res[depth] = max(res[depth], root->val);
        }
        if (root->left)
            dfs(root->left, depth + 1, res);
        if (root->right)
            dfs(root->right, depth + 1, res);
    }
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};