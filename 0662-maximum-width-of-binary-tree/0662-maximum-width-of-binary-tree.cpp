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
    typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ull>> q;
        q.push({root, 0});
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res = max(res, (int)(q.back().second - q.front().second + 1));
            while (size--) {
                TreeNode* curr = q.front().first;
                ull idx = q.front().second;
                q.pop();
                if (curr->left) {
                    q.push({curr->left, 2 * idx + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * idx + 2});
                }
            }
        }
        return res;
    }
};