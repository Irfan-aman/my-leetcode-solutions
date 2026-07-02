class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {//0 1 BFS
        if (grid[0][0] && health == 1)
            return false;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_front({0,0});
        while (!dq.empty()) {
            auto [r,c]=dq.front();
            dq.pop_front();
            if (r == m - 1 && c == n - 1)
                return health > dist[r][c];
            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if(dist[r][c]+grid[x][y]<dist[x][y]){
                        dist[x][y]=dist[r][c]+grid[x][y];
                        if(grid[x][y]){
                            dq.push_back({x,y});
                        }else dq.push_front({x, y});
                    }
                    
                }
            }
        }
        return health>dist[m-1][n-1];
    }
};