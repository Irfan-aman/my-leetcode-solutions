class Solution {
public:
    typedef long long ll;
    int m, n;
    ll dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;
        ll curr = grid[r][c];
        grid[r][c] = 0;
        ll left = dfs(grid, r, c - 1);
        ll right = dfs(grid, r, c + 1);
        ll up = dfs(grid, r - 1, c);
        ll down = dfs(grid, r + 1, c);
        return curr + left + right + up + down;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                ll islandSum = dfs(grid, i, j);
                if (islandSum % k == 0)
                    count++;
            }
        }
        return count;
    }
};