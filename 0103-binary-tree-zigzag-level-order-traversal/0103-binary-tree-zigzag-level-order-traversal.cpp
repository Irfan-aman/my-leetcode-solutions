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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool zigzag = false; // false =left to right and true = right to left
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevel;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (zigzag)
                reverse(currLevel.begin(), currLevel.end());
            res.push_back(currLevel);
            zigzag = !zigzag;
        }
        return res;
    }
};