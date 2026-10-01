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
    void dfs(TreeNode* root, int depth, map<int, vector<int>>& mp) {
        mp[depth].push_back(root->val);
        if (root->left)
            dfs(root->left, depth + 1, mp);
        if (root->right)
            dfs(root->right, depth + 1, mp);
    }
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        map<int, vector<int>> mp;
        dfs(root, 0, mp);
        vector<int> largestVal;
        for (auto& it : mp) {
            int maxi = INT_MIN;
            for (int& x : it.second) {
                maxi = max(maxi, x);
            }
            largestVal.push_back(maxi);
        }
        return largestVal;
    }
};