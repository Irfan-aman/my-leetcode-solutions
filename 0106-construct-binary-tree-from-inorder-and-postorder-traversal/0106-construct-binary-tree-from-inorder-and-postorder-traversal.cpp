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
    int findInorderIdx(vector<int>& inorder, int val, int st, int end) {
        for (int i = st; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildRecursively(vector<int>& inorder, vector<int>& postorder,
                               int inSt, int inEnd, int postSt, int postEnd) {
        if (inSt >inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int i = findInorderIdx(inorder, postorder[postEnd], inSt, inEnd);
        int leftSize = i - inSt;
        int rightSize = inEnd - i;
        root->left = buildRecursively(inorder, postorder, inSt, i - 1, postSt,
                                      postSt + leftSize - 1);
        root->right = buildRecursively(inorder, postorder, i + 1, inEnd,
                                       postEnd - rightSize, postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildRecursively(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};