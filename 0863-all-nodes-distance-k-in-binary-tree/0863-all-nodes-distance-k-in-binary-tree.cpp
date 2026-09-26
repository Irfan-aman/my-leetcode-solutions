/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* tar = NULL;
    void inorder(TreeNode* root, TreeNode* target) {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        inorder(root->left, target);
        if (root->val == target->val)
            tar = root;
        if (root->right)
            parent[root->right] = root;
        inorder(root->right, target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root, target);
        queue<TreeNode*> q;
        q.push(tar);
        vector<int> res;
        vector<int> vis(501, false);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> allNodes;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                vis[curr->val] = true;
                allNodes.push_back(curr->val);
                if (curr->left && !vis[curr->left->val])
                    q.push(curr->left);
                if (curr->right && !vis[curr->right->val])
                    q.push(curr->right);
                if (parent.count(curr) && !vis[parent[curr]->val])
                    q.push(parent[curr]);
            }
            if (level == k) {
                res = allNodes;
                break;
            }
            level++;
        }
        return res;
    }
};