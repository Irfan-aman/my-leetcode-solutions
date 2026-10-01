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
    TreeNode* startNode;
    vector<TreeNode*> parent;
    void findStart(TreeNode* root, int start) {
        if (!root)
            return;
        if (root->val == start) {
            startNode = root;
        }
        if (root->left) {
            parent[root->left->val] = root;
            findStart(root->left, start);
        }
        if (root->right) {
            parent[root->right->val] = root;
            findStart(root->right, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        startNode = NULL;
        parent.resize(100001, NULL);
        findStart(root, start);
        vector<bool> vis(100001, false);
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode->val] = true;
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool atleatOne = false;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left->val]) {
                    q.push(curr->left);
                    vis[curr->left->val] = true;
                    atleatOne = true;
                }
                if (curr->right && !vis[curr->right->val]) {
                    q.push(curr->right);
                    vis[curr->right->val] = true;
                    atleatOne = true;
                }
                if (parent[curr->val] && !vis[parent[curr->val]->val]) {
                    q.push(parent[curr->val]);
                    vis[parent[curr->val]->val] = true;
                    atleatOne = true;
                }
            }
            if (atleatOne) {
                time++;
            }
        }
        return time;
    }
};