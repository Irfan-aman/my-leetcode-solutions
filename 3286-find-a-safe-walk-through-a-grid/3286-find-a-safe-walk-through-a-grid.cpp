class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    typedef pair<int,pair<int,int>> ppi;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0] && health == 1)
            return false;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0,0}});
        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == m - 1 && c == n - 1)
                return health > d;
            if(d > dist[r][c])
                continue;
            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if(d+grid[x][y]<dist[x][y]){
                        dist[x][y]=d+grid[x][y];
                        pq.push({dist[x][y],{x, y}});
                    }
                    
                }
            }
        }
        return health>dist[m-1][n-1];
    }
};