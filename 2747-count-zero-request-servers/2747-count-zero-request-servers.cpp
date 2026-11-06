class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = logs.size();
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int q = queries.size();
        vector<pair<int, int>> timeIdx(q);
        vector<int> result(q);
        for (int i = 0; i < q; i++) {
            timeIdx[i] = {queries[i], i};
        }
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        sort(timeIdx.begin(), timeIdx.end());
        for (auto& [time, idx] : timeIdx) {
            int start = time - x;
            int end = time;
            // expanding
            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }
            // shrinking
            while (i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            result[idx] = n - mp.size();
        }
        return result;
    }
};