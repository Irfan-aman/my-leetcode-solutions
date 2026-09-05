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
    vector<TreeNode*> res;
    string getSubTreeStr(TreeNode* root, unordered_map<string, int>& mp) {
        if (!root)
            return "N";
        string str = to_string(root->val) + "," +
                     getSubTreeStr(root->left, mp) +
                     getSubTreeStr(root->right, mp);
        if (mp[str] == 1) {
            res.push_back(root);
        }
        mp[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        getSubTreeStr(root, mp);
        return res;
    }
};