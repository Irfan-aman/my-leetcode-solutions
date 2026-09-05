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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> oddNodes;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (flag)
                    oddNodes.push_back(curr);
            }
            if (flag) {
                int l = 0, h = oddNodes.size() - 1;
                while (l < h) {
                    swap(oddNodes[l]->val, oddNodes[h]->val);
                    l++;
                    h--;
                }
            }
            flag = !flag;
        }
        return root;
    }
};