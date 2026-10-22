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
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int n) {
        if ((n & 1) == 0) { // even
            return {};
        }
        if (n == 1) {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        if (mp.find(n) != mp.end())
            return mp[n];
        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2) {
            auto L = (mp.find(i) != mp.end()) ? mp[i] : solve(i);
            auto R = (mp.find(n - i - 1) != mp.end()) ? mp[n - i - 1]
                                                      : solve(n - i - 1);
            for (auto& leftN : L) {
                for (auto& rightN : R) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftN;
                    root->right = rightN;
                    res.push_back(root);
                }
            }
        }
        return mp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) { return solve(n); }
};