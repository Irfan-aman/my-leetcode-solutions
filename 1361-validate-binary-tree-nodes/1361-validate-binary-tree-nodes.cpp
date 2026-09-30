class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        unordered_map<int, int> childToParent;
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < n; i++) {
            int node = i;
            int leftNode = leftChild[i], rightNode = rightChild[i];
            if (leftNode != -1) {
                if (childToParent.count(leftNode))
                    return false;
                childToParent[leftNode] = node;
                tree[node].push_back(leftNode);
            }
            if (rightNode != -1) {
                if (childToParent.count(rightNode))
                    return false;
                childToParent[rightNode] = node;
                tree[node].push_back(rightNode);
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (childToParent.count(i) == 0) {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        if (root == -1)
            return false;
        int count = 0;
        queue<int> q;
        q.push(root);
        vector<bool> vis(n, false);
        vis[root] = true;
        while (!q.empty()) {
            int curr = q.front();
            count++;
            q.pop();
            for (auto nbr : tree[curr]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
        return count == n;
    }
};