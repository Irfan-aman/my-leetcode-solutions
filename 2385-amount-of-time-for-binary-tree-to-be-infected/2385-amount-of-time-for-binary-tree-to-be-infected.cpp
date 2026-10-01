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
    unordered_map<TreeNode*, TreeNode*> parent;
    void findStart(TreeNode* root, int start) {
        if (!root)
            return;
        if (root->val == start) {
            startNode = root;
        }
        if (root->left) {
            parent[root->left] = root;
            findStart(root->left, start);
        }
        if (root->right) {
            parent[root->right] = root;
            findStart(root->right, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        startNode = NULL;
        findStart(root, start);
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(startNode);
        vis.insert(startNode);
        int time = -1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && vis.find(curr->left) == vis.end()) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if (curr->right && vis.find(curr->right) == vis.end()) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if (parent.find(curr) != parent.end() &&
                    vis.find(parent[curr]) == vis.end()) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                }
            }
            time++;
        }
        return time;
    }
};