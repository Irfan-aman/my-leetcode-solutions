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
    unordered_map<int, int> mp;
    void dfs(TreeNode* root, int level) {
        if (!root)
            return;
        mp[level] += root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int res = -1;
        int maxSum = INT_MIN;
        for (auto& it : mp) {
            if (it.second > maxSum || (it.second==maxSum && it.first<res)) {
                res = it.first;
                maxSum = it.second;
            }
        }
        return res;
    }
};