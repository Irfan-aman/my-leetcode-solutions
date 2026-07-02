class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0] && health == 1)
            return false;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        best[0][0] = startHealth;
        q.push({{0, 0}, startHealth});
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int hlth = q.front().second;
            if (r == m - 1 && c == n - 1 && hlth > 0)
                return true;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newHealth = hlth - grid[x][y];
                    if (newHealth <= 0)continue;
                    if (newHealth <= best[x][y]) continue;
                    best[x][y] = newHealth;
                    q.push({{x, y}, newHealth});
                }
            }
        }
        return false;
    }
};