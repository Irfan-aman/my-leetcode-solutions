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
    int MOD=1e9+7;
    int totalSum;
    long maxP ;
    int treeSum(TreeNode* root) {
        if (!root)
            return 0;
        int leftSum = treeSum(root->left);
        int rightSum = treeSum(root->right);
        long subTreeSum = root->val + leftSum + rightSum;
        maxP = max((long)maxP, subTreeSum * (totalSum - subTreeSum));
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if (!root)
            return 0;
        totalSum = treeSum(root);
        maxP=0;
        treeSum(root);
        return maxP%MOD;
    }
};