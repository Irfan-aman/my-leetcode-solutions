class Solution {
public:
    typedef tuple<int, int, int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<vector<int>> res(n, vector<int>(k + 1, INT_MAX));
        priority_queue<T, vector<T>, greater<T>> minHeap;
        res[0][1] = 0;
        minHeap.push({0, 0, 1});
        while (!minHeap.empty()) {
            auto [d, u, count] = minHeap.top();
            minHeap.pop();
            if (res[u][count] < d)
                continue;
            if (u == n - 1) {
                return d;
            }
            for (auto& [v, wt] : adj[u]) {
                int newCount = labels[u] == labels[v] ? count + 1 : 1;
                if (newCount > k)
                    continue;
                if (d + wt < res[v][newCount]) {
                    res[v][newCount] = d + wt;
                    minHeap.push({d + wt, v, newCount});
                }
            }
        }
        return -1;
    }
};