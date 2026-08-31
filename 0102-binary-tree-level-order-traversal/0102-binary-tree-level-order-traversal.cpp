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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> eachLevel;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                res.push_back(eachLevel);
                if (q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                    eachLevel.clear();
                    continue;
                }
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            eachLevel.push_back(curr->val);
        }
        return res;
    }
};