class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> Row(m, 0), Col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    Row[i]++;
                    Col[j]++;
                }
            }
        }
        int totalServers = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (Row[i] > 1 || Col[j] > 1)) {
                    totalServers++;
                }
            }
        }
        return totalServers;
    }
};