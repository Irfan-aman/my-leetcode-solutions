class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<bool> sus(n, false); // suspecious
        sus[k] = true;
        for (auto& it : invocations) {
            int u = it[0], v = it[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int& nbr : adj[u]) {
                indegree[nbr]--;
                if (!sus[nbr]) {
                    sus[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (sus[i] && indegree[i]) {
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            } else if (!sus[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};