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
class Info {
public:
    bool isBst;
    int min, max, sum;
    Info(bool isBst, int min, int max, int sum) {
        this->isBst = isBst;
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};
class Solution {
public:
    int res;
    Info solve(TreeNode* root) {
        if (!root)
            return Info(true, INT_MAX, INT_MIN, 0);
        Info L = solve(root->left);
        Info R = solve(root->right);
        int mini = min({L.min, R.min, root->val});
        int maxi = max({L.max, R.max, root->val});
        int totalSum = L.sum + R.sum + root->val;
        if (L.isBst && R.isBst && root->val > L.max && root->val < R.min) {
            res = max(res, totalSum);
            return Info(true, mini, maxi, totalSum);
        }
        return Info(false, mini, maxi, 0);
    }
    int maxSumBST(TreeNode* root) {
        res = 0;
        solve(root);
        return res;
    }
};