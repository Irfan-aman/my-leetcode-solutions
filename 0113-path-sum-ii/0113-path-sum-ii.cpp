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
    vector<vector<int>> res;
    void pathSumHelper(TreeNode* root, int currSum, int& targetSum,
                       vector<int> temp) {
        if (!root)
            return;

        currSum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (currSum == targetSum) {
                res.push_back(temp);
            }
            return;
        }
        pathSumHelper(root->left, currSum, targetSum, temp);
        pathSumHelper(root->right, currSum, targetSum, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int currSum = 0;
        pathSumHelper(root, currSum, targetSum, temp);
        return res;
    }
};