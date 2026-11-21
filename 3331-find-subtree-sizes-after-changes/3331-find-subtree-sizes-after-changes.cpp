class Solution {
public:
    unordered_map<int, vector<int>> adj; //<node,vector<child>>
    vector<int> last;
    vector<int> resSize;
    void dfs(vector<int>& parent, string& s, int i) {
        int c = s[i] - 'a';
        int nearAnc = last[c];
        last[c] = i;

        for (int child : adj[i]) {
            dfs(parent, s, child);
        }
        last[c] = nearAnc;
        if (i != 0) {
            int newParent = parent[i];
            if (nearAnc != -1) {
                newParent = nearAnc;
            }
            parent[i] = newParent;
            resSize[newParent] += resSize[i];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        last.resize(26, -1);
        resSize.resize(n, 1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(parent, s, 0);
        return resSize;
    }
};