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
    int res;
    void solve(TreeNode* root, vector<int>& freq) {
        if (!root)
            return;
        freq[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            int oddFreq = 0;
            for (int i = 1; i <= 9; i++) {
                if (freq[i] & 1)
                    oddFreq++;
            }
            if (oddFreq <= 1)
                res++;
        }
        solve(root->left, freq);
        solve(root->right, freq);
        freq[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        res = 0;
        vector<int> freq(10, 0);
        solve(root, freq);
        return res;
    }
};