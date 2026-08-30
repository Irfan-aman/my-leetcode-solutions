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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> res;
        int lastElem = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                res.push_back(lastElem);
                if (q.empty())
                    break;
                else {
                    q.push(NULL);
                    continue;
                }
            } else if (curr != NULL)
                lastElem = curr->val;

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        return res;
    }
};